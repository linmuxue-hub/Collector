/* add user code begin Header */
/**
  **************************************************************************
  * @file     at32f435_437_int.c
  * @brief    main interrupt service routines.
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */
/* add user code end Header */

/* includes ------------------------------------------------------------------*/
#include "at32f435_437_int.h"
/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include "at32f435_437_wk_config.h"
#include "wk_adc.h"
#include "wk_i2c.h"
#include "flash.h"
#include "math.h"
#include "gync.h"
#include "acqboard_config.h"
#include "fog.h"
#include "adc.h"
#include "alarm.h"
#include "calibration.h"
/* add user code end private includes */

/* private typedef -----------------------------------------------------------*/
/* add user code begin private typedef */
int m;
/* add user code end private typedef */

/* private define ------------------------------------------------------------*/
/* add user code begin private define */

/* add user code end private define */

/* private macro -------------------------------------------------------------*/
/* add user code begin private macro */

/* add user code end private macro */

/* private variables ---------------------------------------------------------*/
/* add user code begin private variables */

/* add user code end private variables */

/* private function prototypes --------------------------------------------*/
/* add user code begin function prototypes */

/* add user code end function prototypes */

/* private user code ---------------------------------------------------------*/
/* add user code begin 0 */

/* add user code end 0 */

/* external variables ---------------------------------------------------------*/
/* add user code begin external variables */
int adc_counter;
/* add user code end external variables */

/**
  * @brief  this function handles nmi exception.
  * @param  none
  * @retval none
  */
void NMI_Handler(void)
{
  /* add user code begin NonMaskableInt_IRQ 0 */

  /* add user code end NonMaskableInt_IRQ 0 */

  /* add user code begin NonMaskableInt_IRQ 1 */

  /* add user code end NonMaskableInt_IRQ 1 */
}

/**
  * @brief  this function handles hard fault exception.
  * @param  none
  * @retval none
  */
void HardFault_Handler(void)
{
  /* add user code begin HardFault_IRQ 0 */

  /* add user code end HardFault_IRQ 0 */
  /* go to infinite loop when hard fault exception occurs */
  while (1)
  {
    /* add user code begin W1_HardFault_IRQ 0 */

    /* add user code end W1_HardFault_IRQ 0 */
  }
}

/**
  * @brief  this function handles memory manage exception.
  * @param  none
  * @retval none
  */
void MemManage_Handler(void)
{
  /* add user code begin MemoryManagement_IRQ 0 */

  /* add user code end MemoryManagement_IRQ 0 */
  /* go to infinite loop when memory manage exception occurs */
  while (1)
  {
    /* add user code begin W1_MemoryManagement_IRQ 0 */

    /* add user code end W1_MemoryManagement_IRQ 0 */
  }
}

/**
  * @brief  this function handles bus fault exception.
  * @param  none
  * @retval none
  */
void BusFault_Handler(void)
{
  /* add user code begin BusFault_IRQ 0 */

  /* add user code end BusFault_IRQ 0 */
  /* go to infinite loop when bus fault exception occurs */
  while (1)
  {
    /* add user code begin W1_BusFault_IRQ 0 */

    /* add user code end W1_BusFault_IRQ 0 */
  }
}

/**
  * @brief  this function handles usage fault exception.
  * @param  none
  * @retval none
  */
void UsageFault_Handler(void)
{
  /* add user code begin UsageFault_IRQ 0 */

  /* add user code end UsageFault_IRQ 0 */
  /* go to infinite loop when usage fault exception occurs */
  while (1)
  {
    /* add user code begin W1_UsageFault_IRQ 0 */

    /* add user code end W1_UsageFault_IRQ 0 */
  }
}

/**
  * @brief  this function handles svcall exception.
  * @param  none
  * @retval none
  */
void SVC_Handler(void)
{
  /* add user code begin SVCall_IRQ 0 */

  /* add user code end SVCall_IRQ 0 */
  /* add user code begin SVCall_IRQ 1 */

  /* add user code end SVCall_IRQ 1 */
}

/**
  * @brief  this function handles debug monitor exception.
  * @param  none
  * @retval none
  */
void DebugMon_Handler(void)
{
  /* add user code begin DebugMonitor_IRQ 0 */

  /* add user code end DebugMonitor_IRQ 0 */
  /* add user code begin DebugMonitor_IRQ 1 */

  /* add user code end DebugMonitor_IRQ 1 */
}

/**
  * @brief  this function handles pendsv_handler exception.
  * @param  none
  * @retval none
  */
void PendSV_Handler(void)
{
  /* add user code begin PendSV_IRQ 0 */

  /* add user code end PendSV_IRQ 0 */
  /* add user code begin PendSV_IRQ 1 */

  /* add user code end PendSV_IRQ 1 */
}

/**
  * @brief  this function handles systick handler.
  * @param  none
  * @retval none
  */
void SysTick_Handler(void)
{
  /* add user code begin SysTick_IRQ 0 */

  /* add user code end SysTick_IRQ 0 */


  /* add user code begin SysTick_IRQ 1 */

  /* add user code end SysTick_IRQ 1 */
}

/**
  * @brief  this function handles TMR2 handler.
  * @param  none
  * @retval none
  */
/*
TMR2_GLOBAL_IRQHandler函数：
触发：定时器溢出中断,每1ms触发一次
功能：产生SYNC脉冲,开启TMR3定时器计数
*/
void TMR2_GLOBAL_IRQHandler(void)
{
  /* add user code begin TMR2_GLOBAL_IRQ 0 */
	if(tmr_interrupt_flag_get(TMR2, TMR_OVF_FLAG) != RESET)
  {
		gpio_bits_set(GPIOA, GPIO_PINS_9);
		gpio_bits_reset(GPIOA, GPIO_PINS_9);
		tmr_counter_enable(TMR3, TRUE);
		tmr_flag_clear(TMR2, TMR_OVF_FLAG);
  }
  /* add user code end TMR2_GLOBAL_IRQ 0 */


  /* add user code begin TMR2_GLOBAL_IRQ 1 */

  /* add user code end TMR2_GLOBAL_IRQ 1 */
}

/**
  * @brief  this function handles TMR3 handler.
  * @param  none
  * @retval none
  */
/*
TMR3_GLOBAL_IRQHandler函数：
触发：定时器溢出中断,触发时间极短
功能：延长SYNC脉冲维持时间,关闭TMR3定时器计数,开启ADC之外的数据传输
*/
void TMR3_GLOBAL_IRQHandler(void)
{
  /* add user code begin TMR3_GLOBAL_IRQ 0 */
	if(tmr_interrupt_flag_get(TMR3, TMR_OVF_FLAG) != RESET)
  {
		tmr_counter_enable(TMR3, FALSE);
		encode_fog_transmit_t(&Fog_Transmit,IXZ_F50X_X,IXZ_F50X_Y,IXZ_F50X_Z,ADCData);
//		err_test(&Fog_Transmit);
		err_check(&Fog_Transmit);
		dma_channel_enable(DMA1_CHANNEL7, TRUE);
		if(wk_adc_counter != 4)
			wk_adc_counter++;
		else{
			adc_ordinary_software_trigger_enable(ADC1, TRUE);
			wk_adc_counter = 0;
		}
		dma_channel_enable(DMA1_CHANNEL2, TRUE);
    dma_channel_enable(DMA1_CHANNEL4, TRUE);
    dma_channel_enable(DMA1_CHANNEL6, TRUE);
		i2c_receive_data();
		tmr_flag_clear(TMR3, TMR_OVF_FLAG);
  }
  /* add user code end TMR3_GLOBAL_IRQ 0 */


  /* add user code begin TMR3_GLOBAL_IRQ 1 */

  /* add user code end TMR3_GLOBAL_IRQ 1 */
}

/**
  * @brief  this function handles TMR4 handler.
  * @param  none
  * @retval none
  */
/*
TMR4_GLOBAL_IRQHandler函数：
触发：定时器溢出中断,100ms触发一次
功能：判断当前温度和设定温度的差,大于阈值认为未稳定,连续5s内未大于阈值认为稳定,开始定时器5采集ADC数据
*/
void TMR4_GLOBAL_IRQHandler(void)
{
  /* add user code begin TMR4_GLOBAL_IRQ 0 */
	if(tmr_interrupt_flag_get(TMR4, TMR_OVF_FLAG) != RESET)
  {
		if(calibration_counter == -1){
			if(fabs(AcqBoard_Config.target_temp - adc_temperature) > TEMPREATURE_THRESHOLD){
				stable_temp_counter = 0;
			}else{
				stable_temp_counter++;
				if(stable_temp_counter == 50){
					stable_temp_counter = 0;
					calibration_counter = 0;
					tmr_counter_enable(TMR5, TRUE);
				}
			}
		}else if(calibration_counter == 2000){
			if(buffer_write[12] == 0x1111){
				flash_write(FLASH_ADDRESS_START, buffer_write, BUFEER_SIZE);
				tmr_counter_enable(TMR4, FALSE);
			}else
				Calibration();
		}
		tmr_flag_clear(TMR4, TMR_OVF_FLAG);
	}
  /* add user code end TMR4_GLOBAL_IRQ 0 */


  /* add user code begin TMR4_GLOBAL_IRQ 1 */

  /* add user code end TMR4_GLOBAL_IRQ 1 */
}

/**
  * @brief  this function handles I2C2 Event handler.
  * @param  none
  * @retval none
  */
void I2C2_EVT_IRQHandler(void)
{
  /* add user code begin I2C2_EVT_IRQ 0 */
	i2c_evt_irq_handler(&hi2cx);
  /* add user code end I2C2_EVT_IRQ 0 */
  /* add user code begin I2C2_EVT_IRQ 1 */

  /* add user code end I2C2_EVT_IRQ 1 */
}

/**
  * @brief  this function handles I2C2 Error handler.
  * @param  none
  * @retval none
  */
void I2C2_ERR_IRQHandler(void)
{
  /* add user code begin I2C2_ERR_IRQ 0 */
	i2c_err_irq_handler(&hi2cx);
  /* add user code end I2C2_ERR_IRQ 0 */
  /* add user code begin I2C2_ERR_IRQ 1 */

  /* add user code end I2C2_ERR_IRQ 1 */
}

/**
  * @brief  this function handles EXINT Line [15:10] handler.
  * @param  none
  * @retval none
  */
/*
EXINT15_10_IRQHandler函数：
触发：DRL引脚下降沿中断
功能：启动ADC数据采集
*/
void EXINT15_10_IRQHandler(void)
{
  /* add user code begin EXINT15_10_IRQ 0 */
	if(exint_interrupt_flag_get(EXINT_LINE_12) != RESET)
  {
		m++;
		adc_counter = 0;
		gpio_bits_reset(CS_AX_GPIO_PORT, CS_AX_PIN);
		dma_channel_enable(DMA2_CHANNEL1, TRUE);
		spi_enable(SPI2, TRUE);
		exint_flag_clear(EXINT_LINE_12);
  }
  /* add user code end EXINT15_10_IRQ 0 */
  /* add user code begin EXINT15_10_IRQ 1 */

  /* add user code end EXINT15_10_IRQ 1 */
}

/**
  * @brief  this function handles TMR5 handler.
  * @param  none
  * @retval none
  */
/*
TMR5_GLOBAL_IRQHandler函数：
触发：定时器溢出中断
功能：采集2000个温度稳定后的 ADC 空载数据,累加在一起---温度稳定后，只需收集足够数量的数据即可，不要求连续
*/
void TMR5_GLOBAL_IRQHandler(void)
{
  /* add user code begin TMR5_GLOBAL_IRQ 0 */
	if(tmr_interrupt_flag_get(TMR5, TMR_OVF_FLAG) != RESET)
  {
		if(calibration_counter >= 0 && calibration_counter < 2000){
			adc_x_sum += Fog_Transmit.Acc_X;
			adc_y_sum += Fog_Transmit.Acc_Y;
			adc_z_sum += Fog_Transmit.Acc_Z;
			calibration_counter++;
		}else{
			tmr_counter_enable(TMR5, FALSE);
		}
		tmr_flag_clear(TMR5, TMR_OVF_FLAG);
  }
  /* add user code end TMR5_GLOBAL_IRQ 0 */


  /* add user code begin TMR5_GLOBAL_IRQ 1 */

  /* add user code end TMR5_GLOBAL_IRQ 1 */
}

/**
  * @brief  this function handles TMR6 & DAC handler.
  * @param  none
  * @retval none
  */
void TMR6_DAC_GLOBAL_IRQHandler(void)
{
  /* add user code begin TMR6_DAC_GLOBAL_IRQ 0 */

  /* add user code end TMR6_DAC_GLOBAL_IRQ 0 */


  /* add user code begin TMR6_DAC_GLOBAL_IRQ 1 */

  /* add user code end TMR6_DAC_GLOBAL_IRQ 1 */
}

/**
  * @brief  this function handles DMA1 Channel 1 handler.
  * @param  none
  * @retval none
  */
/*
DMA1_Channel1_IRQHandler函数：
触发：X轴陀螺仪数据接收完毕
功能：将陀螺仪数据封装到结构体里面
*/
void DMA1_Channel1_IRQHandler(void)
{
  /* add user code begin DMA1_Channel1_IRQ 0 */
	if(dma_interrupt_flag_get(DMA1_FDT1_FLAG) != RESET)
  {
		gync_x_handler(gync_x_receive);
		dma_flag_clear(DMA1_FDT1_FLAG);
  }
  /* add user code end DMA1_Channel1_IRQ 0 */
  /* add user code begin DMA1_Channel1_IRQ 1 */

  /* add user code end DMA1_Channel1_IRQ 1 */
}

/**
  * @brief  this function handles DMA1 Channel 2 handler.
  * @param  none
  * @retval none
  */
/*
DMA1_Channel2_IRQHandler函数：
触发：向X轴陀螺仪发送命令完毕
功能：关闭DMA,置位DMA计数器
*/
void DMA1_Channel2_IRQHandler(void)
{
  /* add user code begin DMA1_Channel2_IRQ 0 */
	if(dma_interrupt_flag_get(DMA1_FDT2_FLAG) != RESET)
  {
		dma_channel_enable(DMA1_CHANNEL2, FALSE); 
    dma_data_number_set(DMA1_CHANNEL2, 1);
    dma_flag_clear(DMA1_FDT2_FLAG);
  }
  /* add user code end DMA1_Channel2_IRQ 0 */
  /* add user code begin DMA1_Channel2_IRQ 1 */

  /* add user code end DMA1_Channel2_IRQ 1 */
}

/**
  * @brief  this function handles DMA1 Channel 3 handler.
  * @param  none
  * @retval none
  */
/*
DMA1_Channel3_IRQHandler函数：
触发：Y轴陀螺仪数据接收完毕
功能：将陀螺仪数据封装到结构体里面
*/
void DMA1_Channel3_IRQHandler(void)
{
  /* add user code begin DMA1_Channel3_IRQ 0 */
	if(dma_interrupt_flag_get(DMA1_FDT3_FLAG) != RESET)
  {
		gync_y_handler(gync_y_receive);
		dma_flag_clear(DMA1_FDT3_FLAG);
  }
  /* add user code end DMA1_Channel3_IRQ 0 */
  /* add user code begin DMA1_Channel3_IRQ 1 */

  /* add user code end DMA1_Channel3_IRQ 1 */
}

/**
  * @brief  this function handles DMA1 Channel 4 handler.
  * @param  none
  * @retval none
  */
/*
DMA1_Channel4_IRQHandler函数：
触发：向Y轴陀螺仪发送命令完毕
功能：关闭DMA,置位DMA计数器
*/
void DMA1_Channel4_IRQHandler(void)
{
  /* add user code begin DMA1_Channel4_IRQ 0 */
	if(dma_interrupt_flag_get(DMA1_FDT4_FLAG) != RESET)
  {
    dma_channel_enable(DMA1_CHANNEL4, FALSE); 
    dma_data_number_set(DMA1_CHANNEL4, DMA1_CHANNEL4_BUFFER_SIZE);
    dma_flag_clear(DMA1_FDT4_FLAG);
  }
  /* add user code end DMA1_Channel4_IRQ 0 */
  /* add user code begin DMA1_Channel4_IRQ 1 */

  /* add user code end DMA1_Channel4_IRQ 1 */
}

/**
  * @brief  this function handles DMA1 Channel 5 handler.
  * @param  none
  * @retval none
  */
/*
DMA1_Channel5_IRQHandler函数：
触发：Z轴陀螺仪数据接收完毕
功能：将陀螺仪数据封装到结构体里面
*/
void DMA1_Channel5_IRQHandler(void)
{
  /* add user code begin DMA1_Channel5_IRQ 0 */
	if(dma_interrupt_flag_get(DMA1_FDT5_FLAG) != RESET)
  {
		gync_z_handler(gync_z_receive);
		dma_flag_clear(DMA1_FDT5_FLAG);
  }
  /* add user code end DMA1_Channel5_IRQ 0 */
  /* add user code begin DMA1_Channel5_IRQ 1 */

  /* add user code end DMA1_Channel5_IRQ 1 */
}

/**
  * @brief  this function handles DMA1 Channel 6 handler.
  * @param  none
  * @retval none
  */
/*
DMA1_Channel6_IRQHandler函数：
触发：向Z轴陀螺仪发送命令完毕
功能：关闭DMA,置位DMA计数器
*/
void DMA1_Channel6_IRQHandler(void)
{
  /* add user code begin DMA1_Channel6_IRQ 0 */
	if(dma_interrupt_flag_get(DMA1_FDT6_FLAG) != RESET)
  {
    dma_channel_enable(DMA1_CHANNEL6, FALSE); 
    dma_data_number_set(DMA1_CHANNEL6, DMA1_CHANNEL6_BUFFER_SIZE);
    dma_flag_clear(DMA1_FDT6_FLAG);
  }
  /* add user code end DMA1_Channel6_IRQ 0 */
  /* add user code begin DMA1_Channel6_IRQ 1 */

  /* add user code end DMA1_Channel6_IRQ 1 */
}

/**
  * @brief  this function handles DMA1 Channel 7 handler.
  * @param  none
  * @retval none
  */
/*
DMA1_Channel7_IRQHandler函数：
触发：向主机发送数据帧完毕
功能：关闭DMA,置位DMA计数器
*/
void DMA1_Channel7_IRQHandler(void)
{
  /* add user code begin DMA1_Channel7_IRQ 0 */
	if(dma_interrupt_flag_get(DMA1_FDT7_FLAG) != RESET)
 	{
		dma_channel_enable(DMA1_CHANNEL7, FALSE); 
		dma_data_number_set(DMA1_CHANNEL7, DMA1_CHANNEL7_BUFFER_SIZE);
		dma_flag_clear(DMA1_FDT7_FLAG);
 	}
  /* add user code end DMA1_Channel7_IRQ 0 */
  /* add user code begin DMA1_Channel7_IRQ 1 */

  /* add user code end DMA1_Channel7_IRQ 1 */
}

/**
  * @brief  this function handles DMA2 Channel 1 handler.
  * @param  none
  * @retval none
  */
/*
DMA2_Channel1_IRQHandler函数：
触发：任意一轴 ADC 数据接收完毕
功能：切换下一轴 ADC 数据的采集，封装数据到 ADC 结构体
*/
void DMA2_Channel1_IRQHandler(void)
{
  /* add user code begin DMA2_Channel1_IRQ 0 */
	if(dma_interrupt_flag_get(DMA2_FDT1_FLAG) != RESET)
  {
    spi_enable(SPI2, FALSE);
    dma_channel_enable(DMA2_CHANNEL1, FALSE); 
    dma_data_number_set(DMA2_CHANNEL1, DMA2_CHANNEL1_BUFFER_SIZE);
		switch(adc_counter){
			case 0:
				gpio_bits_set(CS_AX_GPIO_PORT, CS_AX_PIN);
				set_ADCData(adc_xyz,adc_counter);
				gpio_bits_reset(CS_AY_GPIO_PORT, CS_AY_PIN);
				dma_channel_enable(DMA2_CHANNEL1, TRUE);
				spi_enable(SPI2, TRUE);
				break;
			case 1:
				gpio_bits_set(CS_AY_GPIO_PORT, CS_AY_PIN);
				set_ADCData(adc_xyz,adc_counter);
				gpio_bits_reset(CS_AZ_GPIO_PORT, CS_AZ_PIN);
				dma_channel_enable(DMA2_CHANNEL1, TRUE);
				spi_enable(SPI2, TRUE);
				break;
			case 2:
				gpio_bits_set(CS_AZ_GPIO_PORT, CS_AZ_PIN);
				set_ADCData(adc_xyz,adc_counter);
				break;
		}
		adc_counter++;
    dma_flag_clear(DMA2_FDT1_FLAG);
	}
  /* add user code end DMA2_Channel1_IRQ 0 */
  /* add user code begin DMA2_Channel1_IRQ 1 */

  /* add user code end DMA2_Channel1_IRQ 1 */
}

void DMA2_Channel2_IRQHandler(void)
{
	i2c_dma_tx_irq_handler(&hi2cx);
}

/*
DMA2_Channel3_IRQHandler函数：
触发：i2c 数据接收完毕
功能：拼接 i2c 数据，还原出采集板温度数据
*/
void DMA2_Channel3_IRQHandler(void)
{
	i2c_dma_rx_irq_handler(&hi2cx);
	i2c_temperature_temp = (i2c_rx_buf[0] << 8)| i2c_rx_buf[1];
	i2c_temperature = decode_tmp117(i2c_temperature_temp);
}

/**
  * @brief  this function handles DMA2 Channel 4 handler.
  * @param  none
  * @retval none
  */
/*
DMA2_Channel4_IRQHandler函数：
触发：adc 数据接收完毕
功能：还原出采集板温度数据，通过PID计算出DAC要设置的电压值，开启DAC
*/
void DMA2_Channel4_IRQHandler(void)
{
  /* add user code begin DMA2_Channel4_IRQ 0 */
	if(dma_interrupt_flag_get(DMA2_FDT4_FLAG))
  {
		adc_temperature_temp = adc_value * 3.3f /4095;
		adc_temperature = 88.56f - 83.36f * adc_temperature_temp;
		dac_value = pid_calculate(adc_temperature);
		dma_channel_enable(DMA2_CHANNEL5, TRUE);
		dac_software_trigger_generate(DAC1_SELECT); 
		dma_flag_clear(DMA2_FDT4_FLAG);
	}
  /* add user code end DMA2_Channel4_IRQ 0 */
  /* add user code begin DMA2_Channel4_IRQ 1 */

  /* add user code end DMA2_Channel4_IRQ 1 */
}

/**
  * @brief  this function handles DMA2 Channel 5 handler.
  * @param  none
  * @retval none
  */
void DMA2_Channel5_IRQHandler(void)
{
  /* add user code begin DMA2_Channel5_IRQ 0 */
	if(dma_interrupt_flag_get(DMA2_FDT5_FLAG) != RESET)
 	 {
		dma_channel_enable(DMA2_CHANNEL5, FALSE); 
		dma_data_number_set(DMA2_CHANNEL5, DMA2_CHANNEL5_BUFFER_SIZE);
		dma_flag_clear(DMA2_FDT5_FLAG);
 	 }
  /* add user code end DMA2_Channel5_IRQ 0 */
  /* add user code begin DMA2_Channel5_IRQ 1 */

  /* add user code end DMA2_Channel5_IRQ 1 */
}

/**
  * @brief  this function handles DMA2 Channel 7 handler.
  * @param  none
  * @retval none
  */
/*
DMA2_Channel7_IRQHandler函数：
触发：采集板配置数据接收完毕
功能：解码配置帧，配置相关信息
*/
void DMA2_Channel7_IRQHandler(void)
{
  /* add user code begin DMA2_Channel7_IRQ 0 */
	if(dma_interrupt_flag_get(DMA2_FDT7_FLAG) != RESET)
 	 {
		decode_acqboard_config_t(pid_transmit_receive, DMA2_CHANNEL7_BUFFER_SIZE);
		AcqBoard_Config.target_temp = 40.0f;
		AcqBoard_Config.Kp = 0.28f;
		AcqBoard_Config.Ki = 0.009f;
		AcqBoard_Config.Kd = 0.01f;
		if(AcqBoard_Config.GC == 0)
			gpio_bits_reset(GC_GPIO_PORT, GC_PIN);
		else
			gpio_bits_set(GC_GPIO_PORT, GC_PIN);
		dma_flag_clear(DMA2_FDT7_FLAG);
 	 }
  /* add user code end DMA2_Channel7_IRQ 0 */
  /* add user code begin DMA2_Channel7_IRQ 1 */

  /* add user code end DMA2_Channel7_IRQ 1 */
}

/* add user code begin 1 */

/* add user code end 1 */
