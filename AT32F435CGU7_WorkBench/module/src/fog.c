#include "fog.h"
#include "wk_i2c.h"
#include "wk_adc.h"

/*
calculate_checksum函数：
参数：Fog_Transmit_t*---Fog_Transmit_t结构体指针类型,指向需要计算的结构体
功能：计算结构体的CRC,单字节异或校验
*/
uint8_t calculate_checksum(Fog_Transmit_t* transmit) 
{
	uint8_t checksum = 0;	
	size_t i;																	

	uint8_t* data_ptr = (uint8_t*)&transmit->Dg_X;
	for (i = 0; i < sizeof(float) * 3; ++i)
	{
		checksum ^= data_ptr[i]; 
	}

	data_ptr = (uint8_t*)&transmit->Acc_X; 
	for (i = 0; i < sizeof(float) * 3; ++i) 
	{
		checksum ^= data_ptr[i];
	}

	checksum ^= (uint8_t)(transmit->Temp_X);
	checksum ^= (uint8_t)(transmit->Temp_X >> 8);
	checksum ^= (uint8_t)(transmit->Temp_Y);
	checksum ^= (uint8_t)(transmit->Temp_Y >> 8);
	checksum ^= (uint8_t)(transmit->Temp_Z);
	checksum ^= (uint8_t)(transmit->Temp_Z >> 8);
	checksum ^= (uint8_t)(transmit->Acc_Temp);
	checksum ^= (uint8_t)(transmit->Acc_Temp >> 8);
	
	data_ptr = (uint8_t*)&transmit->Recent_Temp; 
	for (i = 0; i < sizeof(float); ++i) 
	{
		checksum ^= data_ptr[i];
	}

	return checksum;
}

/*
uart4_handler函数：
功能：封装Fog_Transmit_t结构体
*/
void encode_fog_transmit_t(Fog_Transmit_t* transmit,IXZ_F50X_t IXZ_F50X_X,IXZ_F50X_t IXZ_F50X_Y,IXZ_F50X_t IXZ_F50X_Z,t_ADCData ADCData)
{
	transmit->Frame_header_01 = 0xAA;
	transmit->Frame_header_02 = 0xAA;
	transmit->Send_count = 00;

	transmit->Dg_X = IXZ_F50X_X.Dg;
	transmit->Dg_Y = IXZ_F50X_Y.Dg;
	transmit->Dg_Z = IXZ_F50X_Z.Dg;

	transmit->Temp_X = IXZ_F50X_X.Temp;
	transmit->Temp_Y = IXZ_F50X_Y.Temp;
	transmit->Temp_Z = IXZ_F50X_Z.Temp;

	transmit->Acc_X = ADCData.Volt1;
	transmit->Acc_Y = ADCData.Volt2;
	transmit->Acc_Z = ADCData.Volt3;

	transmit->Acc_Temp	= (int16_t)i2c_temperature_temp;
	transmit->Recent_Temp = adc_temperature;

	transmit->Check_sum  = calculate_checksum(transmit);
	transmit->Frame_tail = 0xBB;
}
