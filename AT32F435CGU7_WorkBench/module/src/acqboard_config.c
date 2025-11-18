#include "acqboard_config.h"
#include <stdbool.h>
#include "string.h"
#include "math.h"
#include "FDILink.h"

AcqBoard_Config_t AcqBoard_Config;
int AcqBoard_Config_Error_Counter;
/*
误差数据：
e				---	当前误差，e = Pid_Transmit.target_temp - recent_temp;
e_last	---	上次误差
e_sum		---	累加误差，e_sum += e * dt
*/
float e,e_last,e_sum;

/*
电压数据：
delta_u		---	PID计算出的电压	
output_u	---	DAC输出的真实电压，PID计算电压加上温度控制器静态电压
*/
float delta_u,output_u;

float Kp_Max = 1.5f;
float Ki_Max = 0.5f;
float Kd_Max = 0.5f;
float Kp_iTerm;
float Ki_iTerm;
float Kd_iTerm;
float fParam = 0.5f;

FDILink_t FDILink;

/*
Pid_Transmit_t结构体解码函数
*/
void decode_acqboard_config_t(const uint8_t *data,int size)
{
	for(int i = 0; i < size; i++)
	{
		switch(FDILink.RxStatus)
		{
			case FDILink_Frame_Start:
			{
				FDILink_Reset(&FDILink);
				if(data[i] != 0xAA)
					FDILink_Error(&FDILink, AcqBoard_Config_Error_Counter);
				else
					FDILink.RxStatus = FDILink_Frame_CMD;
				break;
			}
			case FDILink_Frame_CMD:
			{
				if(data[i] != 0xDD)
					FDILink_Error(&FDILink, AcqBoard_Config_Error_Counter);
				else
				{
					FDILink.RxStatus = FDILink_Frame_Data;
					FDILink.RxDataLeft = 19;
			  }
				break;
			}
			case FDILink_Frame_Data:
			{
				FDILink.Buffer[FDILink.BufferIndex++] = data[i];
				FDILink.RxDataLeft--;
				if(FDILink.RxDataLeft >= 1)
				  FDILink.CRC_FOG ^= data[i];
				if (FDILink.RxDataLeft == 0)
					FDILink.RxStatus = FDILink_Frame_End;
				break;
			}
			case FDILink_Frame_End:
			{
				if(FDILink.CRC_FOG != FDILink.Buffer[18] || data[i] != 0xBB)
				 FDILink_Error(&FDILink, AcqBoard_Config_Error_Counter);
				else
				{
					FDILink.RxStatus = FDILink_Frame_Start;
				  memcpy(&AcqBoard_Config, &FDILink.Buffer, FDILink.BufferIndex);
				}
				break;
			}
			default:
				break;
		}
	}
}

/*
pid_calculate函数：
在ADC采集到温度后，通过PID来计算DAC所需电压值，电压值转化为数字量输出
ADC每1ms采集一次，考虑dt进行PID运算，dt=0.001s
*/
uint16_t pid_calculate(float temperature)
{
	e = AcqBoard_Config.target_temp - temperature;
	
	Kp_iTerm = LIMIT(AcqBoard_Config.Kp * e, -Kp_Max, Kp_Max);
	
	if(AcqBoard_Config.Ki)
	{
		if(e < 5) 
			e_sum += e * 0.001f;
		Ki_iTerm = AcqBoard_Config.Ki * e_sum;
		if(fabs(Ki_iTerm) > Ki_Max)
		{
			Ki_iTerm = LIMIT(Ki_iTerm, -Ki_Max, Ki_Max);
			e_sum = Ki_iTerm / AcqBoard_Config.Ki;
		}
	}else
		Ki_iTerm = 0.0f;
	
	if(AcqBoard_Config.Kd)
	{
		e = -temperature;
		Kd_iTerm = LIMIT(AcqBoard_Config.Kd * (e - e_last) * 1000, -Kd_Max, Kd_Max);
		e_last += fParam * (e - e_last);
	}else
		Kd_iTerm = 0.0f;
	
	delta_u =  Kp_iTerm + Ki_iTerm + Kd_iTerm;
	output_u = LIMIT(delta_u + 1.5f, 0, 3.3f);
	return (uint16_t)((output_u / 3.3f) * 4095.0f);
}
