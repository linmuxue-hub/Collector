#include "adc.h"
#include "calibration.h"

t_ADCData ADCData;

/*
DataFormatting函数：
参数：Data	---	32位 ADC 原始数据，由采样数据经过移位组合得到
			Vref	---	参考电压，由硬件电路设定，当前值为 5V
			PGA		---	增益，通过GA引脚控制
功能: 将32位 ADC 原始数据转换为对应的电压值
*/
double DataFormatting(uint32_t Data , double Vref ,uint8_t PGA)
{
  double ReadVoltage;
  if(Data & 0x80000000)
  {
    Data = (~Data) & 0xFFFFFFFF;
    ReadVoltage = -(((double)Data) / 2147483647) * ((Vref) / ((double)PGA));
  }
  else
    ReadVoltage =  (((double)Data) / 2147483647) * ((Vref) / ((double)PGA));
	
  return(ReadVoltage);
}


void set_ADCData(const uint8_t* data,int counter)
{
	switch(counter)
	{
		case 0:
			ADCData.Ch1 = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
			if(gpio_output_data_bit_read(GPIOA, GPIO_PINS_15))
				ADCData.Volt1 = DataFormatting(ADCData.Ch1, 5, 1) * ADC_TO_ACC - adc_calibration.g1_offset_x;
			else
				ADCData.Volt1 = DataFormatting(ADCData.Ch1, 5, 16) * ADC_TO_ACC - adc_calibration.g16_offset_x;
			break;
		case 1:
			ADCData.Ch2 = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
			if(gpio_output_data_bit_read(GPIOA, GPIO_PINS_15))
				ADCData.Volt2 = DataFormatting(ADCData.Ch2, 5, 1) * ADC_TO_ACC - adc_calibration.g1_offset_y;
			else
				ADCData.Volt2 = DataFormatting(ADCData.Ch2, 5, 16) * ADC_TO_ACC - adc_calibration.g16_offset_y;
			break;
		case 2:
			ADCData.Ch3 = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
			if(gpio_output_data_bit_read(GPIOA, GPIO_PINS_15))
				ADCData.Volt3 = DataFormatting(ADCData.Ch3, 5, 1) * ADC_TO_ACC - adc_calibration.g1_offset_z;
			else
				ADCData.Volt3 = DataFormatting(ADCData.Ch3, 5, 16) * ADC_TO_ACC - adc_calibration.g16_offset_z;
			break;
	}
}
