#ifndef __ADC_H
#define __ADC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f435_437.h"

#define ADC_TO_ACC 1.0f

typedef struct {
	uint32_t Ch1;
	uint32_t Ch2;
	uint32_t Ch3;
	
	float Volt1;
	float Volt2;
	float Volt3;
} t_ADCData;

extern t_ADCData ADCData;

void set_ADCData(const uint8_t* data,int counter);

#ifdef __cplusplus
}
#endif

#endif
