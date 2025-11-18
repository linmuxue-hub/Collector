#include "calibration.h"
#include <stdbool.h>

ADCOffsetVoltage adc_calibration;
bool first_enter_flag = true;
int calibration_counter = -1;
int stable_temp_counter = 0;
float adc_x_sum;
float adc_y_sum;
float adc_z_sum;
uint16_t buffer_write[BUFEER_SIZE];
uint16_t buffer_read[BUFEER_SIZE];

void Calibration(void){
	const uint16_t* temp;
	if(first_enter_flag){
		adc_calibration.g1_offset_x = adc_x_sum / 2000;
		adc_calibration.g1_offset_y = adc_y_sum / 2000;
		adc_calibration.g1_offset_z = adc_z_sum / 2000;
		temp = (const uint16_t*)&adc_calibration.g1_offset_x;
		buffer_write[0] = temp[0];
		buffer_write[1] = temp[1];
		temp = (const uint16_t*)&adc_calibration.g1_offset_y;
		buffer_write[2] = temp[0];
		buffer_write[3] = temp[1];
		temp = (const uint16_t*)&adc_calibration.g1_offset_z;
		buffer_write[4] = temp[0];
		buffer_write[5] = temp[1];
		adc_x_sum = 0;
		adc_y_sum = 0;
		adc_z_sum = 0;
		GPIOA->odt ^= GPIO_PINS_15;
		first_enter_flag = false;
		calibration_counter = -1;
	}else{
		adc_calibration.g16_offset_x = adc_x_sum / 2000;
		adc_calibration.g16_offset_y = adc_y_sum / 2000;
		adc_calibration.g16_offset_z = adc_z_sum / 2000;
		temp = (const uint16_t*)&adc_calibration.g16_offset_x;
		buffer_write[6] = temp[0];
		buffer_write[7] = temp[1];
		temp = (const uint16_t*)&adc_calibration.g16_offset_y;
		buffer_write[8] = temp[0];
		buffer_write[9] = temp[1];
		temp = (const uint16_t*)&adc_calibration.g16_offset_z;
		buffer_write[10] = temp[0];
		buffer_write[11] = temp[1];
		buffer_write[12] = 0x1111;
//		flash_write(FLASH_ADDRESS_START, buffer_write, BUFEER_SIZE);
	}
}
