#ifndef __CALIBRATION_H
#define __CALIBRATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f435_437.h"

#define BUFEER_SIZE                 13
#define FLASH_ADDRESS_START         0x080FF800
#define TEMPREATURE_THRESHOLD       0.2

typedef struct {
	float g16_offset_x;
	float g16_offset_y;
	float g16_offset_z; 

	float g1_offset_x;
	float g1_offset_y;
	float g1_offset_z;
} ADCOffsetVoltage;

extern ADCOffsetVoltage adc_calibration;
extern int calibration_counter;
extern int stable_temp_counter;
extern float adc_x_sum;
extern float adc_y_sum;
extern float adc_z_sum;
extern uint16_t buffer_write[BUFEER_SIZE];
extern uint16_t buffer_read[BUFEER_SIZE];

void Calibration(void);

#ifdef __cplusplus
}
#endif

#endif
