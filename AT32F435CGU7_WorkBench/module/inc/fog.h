#ifndef __FOG_H
#define __FOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f435_437.h"
#include "gync.h"
#include "adc.h"

#pragma pack(push, 1)
typedef struct
{
	uint8_t Frame_header_01;
	uint8_t Frame_header_02;
	uint8_t Send_count;

	float Dg_X;
	float Dg_Y;
	float Dg_Z;
	
	float Acc_X;
	float Acc_Y;
	float Acc_Z;
	
	int16_t Temp_X;				//转化为真实温度值：Temp_X/16
	int16_t Temp_Y;
	int16_t Temp_Z;
	
	int16_t Acc_Temp;
	float Recent_Temp;
	
	uint8_t Check_sum;
	uint8_t Frame_tail;
}Fog_Transmit_t;
#pragma pack(pop)

void encode_fog_transmit_t(Fog_Transmit_t* transmit,IXZ_F50X_t IXZ_F50X_X,IXZ_F50X_t IXZ_F50X_Y,IXZ_F50X_t IXZ_F50X_Z,t_ADCData ADCData);

#ifdef __cplusplus
}
#endif

#endif
