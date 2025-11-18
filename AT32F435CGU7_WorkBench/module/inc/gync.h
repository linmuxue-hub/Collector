#ifndef __GYNC_H
#define __GYNC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f435_437.h"

/*
三轴陀螺仪的比例系数,由陀螺仪厂家校准后给出,不同陀螺仪的比例系数不同
*/
#define F50X_X_PPM 274305050			//Code Number: 2201044
#define F50X_Y_PPM 274601315			//Code Number: 2301004
#define F50X_Z_PPM 273967543			//Code Number: 2301010
#define TIM_TRANSMIT_HZ 1000

/*
陀螺仪数据结构体：
Dg_raw		---	解码后拼接成的16位角速度数据
Temp_raw	---	解码后拼接成的16位温度数据
Dg				---	角速度的真实数据，角速度真实值 = 16 位原始角速度数据 × 频率 ÷ 比例系数
Temp			---	温度的真实数据,由16位数据转换为真实温度值需要除以16---当前转换在主机端解码函数中完成，暂不除以 16
*/
typedef struct
{ 
	int32_t Dg_raw;
	int16_t Temp_raw;
	float 	Dg;
	int16_t Temp;
}IXZ_F50X_t;

extern IXZ_F50X_t IXZ_F50X_X;
extern IXZ_F50X_t IXZ_F50X_Y;
extern IXZ_F50X_t IXZ_F50X_Z;

void gync_x_handler(const uint8_t *data);
void gync_y_handler(const uint8_t *data);
void gync_z_handler(const uint8_t *data);

#ifdef __cplusplus
}
#endif

#endif
