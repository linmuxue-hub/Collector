#ifndef __ACQBOARD_CONFIG_H
#define __ACQBOARD_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f435_437.h"

#define LIMIT(Data,Min,Max) (Data>Max?Max:(Data<Min)?Min:Data)

/*
AcqBoard_Config_t结构体：
Kp					---	比例系数，决定误差响应的力度
Ki					---	积分系数，用于消除稳态误差
Kd					---	微分系数，用于抑制快速变化的误差
target_temp	---	设定温度
GC					---	增益，非零值为1倍增益，零值为16倍增益
*/
#pragma pack(push, 1)
typedef struct
{
	uint8_t Send_count;

	float 	Kp;
	float 	Ki;
	float 	Kd;
	
	float 	target_temp;
	uint8_t GC;
	
	uint8_t Check_sum;
}AcqBoard_Config_t;
#pragma pack(pop)

extern AcqBoard_Config_t AcqBoard_Config;

void decode_acqboard_config_t(const uint8_t *data,int size);
uint16_t pid_calculate(float temperature);

#ifdef __cplusplus
}
#endif

#endif
