/* add user code begin Header */
/**
  **************************************************************************
  * @file     main.c
  * @brief    main program
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

/* Includes ------------------------------------------------------------------*/
#include "at32f435_437_wk_config.h"
#include "wk_adc.h"
#include "wk_dac.h"
#include "wk_exint.h"
#include "wk_i2c.h"
#include "wk_spi.h"
#include "wk_tmr.h"
#include "wk_usart.h"
#include "wk_dma.h"
#include "wk_gpio.h"
#include "wk_system.h"

/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include "flash.h"
#include "string.h"
#include "calibration.h"
/* add user code end private includes */

/* private typedef -----------------------------------------------------------*/
/* add user code begin private typedef */

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

/**
  * @brief main function.
  * @param  none
  * @retval none
  */
/*
main函数负责初始化外设和开启温度校准
adc所用外设：
gpio: A8	---MCLK	---主时钟,计数达到降噪采样因子就触发DRL脉冲---降噪采样因子：通过SEL1,SEL2电平设置,[SEL0 SEL1]的00、01、10 和 11 对应256、1024、4096 和 16384
			A9	---SYNC	---同步位,每个脉冲到来时,MCLK重新从0开始计数
			A12	---DRL	---就绪位,每个脉冲到来时,触发下降沿中断,开始采样数据
			A15	---GC		---增益位,低电平16倍增益,高电平1倍增益
spi:	B1	---SCK	---SPI时钟,为 ADC 数据采集提供采样时序,低电平空闲,上升沿采样
			B14	---MISO	---单向信号线，仅用于接收数据
			A11	---CS_AX---X轴方向上 ADC 数据的片选信号,默认保持低电平,变为高电平时有效
			A10	---CS_AY---Y轴方向上 ADC 数据的片选信号,默认保持低电平,变为高电平时有效
			B12	---CS_AZ---Z轴方向上 ADC 数据的片选信号,默认保持低电平,变为高电平时有效
tmr1: 用于产生MCLK主时钟,频率1.024MHz
tmr2: 用于产生SYNC脉冲,频率1kHz---通过MCLK频率和降噪采样因子计算得到 1.024MHz/1024 = 1kHz
tmr3: 用于控制SYNC脉冲的高电平持续时间,时间较长可能导致MCLK计数未达到降噪采样因子就归零
dma:  DMA2通道1,用于传输 ADC 数据

陀螺仪所用外设：
usart：UART4---X轴陀螺仪
			 USART3---Y轴陀螺仪
			 USART1---Z轴陀螺仪
uart:  USART2---用于向主机发送数据整合包
dma:	 DMA1通道1,绑定UART4的RX,负责接收来自X轴陀螺仪的输入
			 DMA1通道2,绑定UART4的TX,负责向X轴陀螺仪发送命令,控制其输出数据
			 DMA1通道3,绑定USART3的RX,负责接收来自Y轴陀螺仪的输入
			 DMA1通道4,绑定USART3的TX,负责向Y轴陀螺仪发送命令,控制其输出数据
			 DMA1通道5,绑定USART1的RX,负责接收来自Z轴陀螺仪的输入
			 DMA1通道6,绑定USART1的TX,负责向Z轴陀螺仪发送命令,控制其输出数据
			 DMA1通道7,绑定USART2的TX,负责向主机发送数据整合包
			 
温度传感器所用外设：
i2c：	 i2c2---用于接收来自温度传感器的温度数据
dma:	 DMA2通道2,绑定i2c2的TX
			 DMA2通道3,绑定i2c2的RX
*/
int main(void)
{
  /* add user code begin 1 */

  /* add user code end 1 */

  /* system clock config. */
  wk_system_clock_config();

  /* config periph clock. */
  wk_periph_clock_config();

  /* nvic config. */
  wk_nvic_config();

  /* timebase config. */
  wk_timebase_init();
	
  /* init gpio function. */
  wk_gpio_config();

  /* init adc-common function. */
  wk_adc_common_init();

  /* init adc1 function. */
  wk_adc1_init();

  /* init dma1 channel1 */
  wk_dma1_channel1_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA1_CHANNEL1, 
                        (uint32_t)&UART4->dt, 
                        DMA1_CHANNEL1_MEMORY_BASE_ADDR, 
                        DMA1_CHANNEL1_BUFFER_SIZE);
  dma_channel_enable(DMA1_CHANNEL1, TRUE);

  /* init dma1 channel2 */
  wk_dma1_channel2_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA1_CHANNEL2, 
                        (uint32_t)&UART4->dt, 
                        DMA1_CHANNEL2_MEMORY_BASE_ADDR, 
                        DMA1_CHANNEL2_BUFFER_SIZE);

  /* init dma1 channel3 */
  wk_dma1_channel3_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA1_CHANNEL3, 
                        (uint32_t)&USART3->dt, 
                        DMA1_CHANNEL3_MEMORY_BASE_ADDR, 
                        DMA1_CHANNEL3_BUFFER_SIZE);
  dma_channel_enable(DMA1_CHANNEL3, TRUE);

  /* init dma1 channel4 */
  wk_dma1_channel4_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA1_CHANNEL4, 
                        (uint32_t)&USART3->dt, 
                        DMA1_CHANNEL4_MEMORY_BASE_ADDR, 
                        DMA1_CHANNEL4_BUFFER_SIZE);

  /* init dma1 channel5 */
  wk_dma1_channel5_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA1_CHANNEL5, 
                        (uint32_t)&USART1->dt, 
                        DMA1_CHANNEL5_MEMORY_BASE_ADDR, 
                        DMA1_CHANNEL5_BUFFER_SIZE);
  dma_channel_enable(DMA1_CHANNEL5, TRUE);

  /* init dma1 channel6 */
  wk_dma1_channel6_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA1_CHANNEL6, 
                        (uint32_t)&USART1->dt, 
                        DMA1_CHANNEL6_MEMORY_BASE_ADDR, 
                        DMA1_CHANNEL6_BUFFER_SIZE);

  /* init dma1 channel7 */
  wk_dma1_channel7_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA1_CHANNEL7, 
                        (uint32_t)&USART2->dt, 
                        DMA1_CHANNEL7_MEMORY_BASE_ADDR, 
                        DMA1_CHANNEL7_BUFFER_SIZE);

  /* init dma2 channel1 */
  wk_dma2_channel1_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA2_CHANNEL1, 
                        (uint32_t)&SPI2->dt, 
                        DMA2_CHANNEL1_MEMORY_BASE_ADDR, 
                        DMA2_CHANNEL1_BUFFER_SIZE);

  /* init dma2 channel4 */
  wk_dma2_channel4_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA2_CHANNEL4, 
                        (uint32_t)&ADC1->odt, 
                        DMA2_CHANNEL4_MEMORY_BASE_ADDR, 
                        DMA2_CHANNEL4_BUFFER_SIZE);
  dma_channel_enable(DMA2_CHANNEL4, TRUE);

  /* init dma2 channel5 */
  wk_dma2_channel5_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA2_CHANNEL5, 
                        (uint32_t)DAC1_12BIT_RIGHT, 
                        DMA2_CHANNEL5_MEMORY_BASE_ADDR, 
                        DMA2_CHANNEL5_BUFFER_SIZE);

  /* init dma2 channel7 */
  wk_dma2_channel7_init();
  /* config dma channel transfer parameter */
  /* user need to modify define values DMAx_CHANNELy_XXX_BASE_ADDR and DMAx_CHANNELy_BUFFER_SIZE in at32xxx_wk_config.h */
  wk_dma_channel_config(DMA2_CHANNEL7, 
                        (uint32_t)&USART2->dt, 
                        DMA2_CHANNEL7_MEMORY_BASE_ADDR, 
                        DMA2_CHANNEL7_BUFFER_SIZE);
  dma_channel_enable(DMA2_CHANNEL7, TRUE);

  /* init usart1 function. */
  wk_usart1_init();

  /* init usart2 function. */
  wk_usart2_init();

  /* init usart3 function. */
  wk_usart3_init();

  /* init uart4 function. */
  wk_uart4_init();

  /* init dac function. */
  wk_dac_init();

  /* init spi2 function. */
  wk_spi2_init();

  /* init i2c2 function. */
  wk_i2c2_init();

  /* init exint function. */
  wk_exint_config();

  /* init tmr1 function. */
  wk_tmr1_init();

  /* init tmr2 function. */
  wk_tmr2_init();

  /* init tmr3 function. */
  wk_tmr3_init();

  /* add user code begin 2 */
	gpio_bits_set(GC_GPIO_PORT, GC_PIN);
//	flash_read(FLASH_ADDRESS_START, buffer_read, BUFEER_SIZE);
//	if(buffer_read[12] != 0x1111){								//0x1111是标志位，可以换成任意值
////	if(buffer_read[12] == 0x1111){							//复位用
//		wk_tmr4_init();
//		wk_tmr5_init();
//	}else{
//    memcpy(&adc_calibration.g1_offset_x, &buffer_read[0], sizeof(float));
//		memcpy(&adc_calibration.g1_offset_y, &buffer_read[2], sizeof(float));
//		memcpy(&adc_calibration.g1_offset_z, &buffer_read[4], sizeof(float));
//		memcpy(&adc_calibration.g16_offset_x, &buffer_read[6], sizeof(float));
//		memcpy(&adc_calibration.g16_offset_y, &buffer_read[8], sizeof(float));
//		memcpy(&adc_calibration.g16_offset_z, &buffer_read[10], sizeof(float));
//	}
  /* add user code end 2 */

  while(1)
  {
    /* add user code begin 3 */

    /* add user code end 3 */
  }
}

  /* add user code begin 4 */

  /* add user code end 4 */
