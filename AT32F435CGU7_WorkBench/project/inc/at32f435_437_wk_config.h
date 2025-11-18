/* add user code begin Header */
/**
  **************************************************************************
  * @file     at32f435_437_wk_config.h
  * @brief    header file of work bench config
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

/* define to prevent recursive inclusion -----------------------------------*/
#ifndef __AT32F435_437_WK_CONFIG_H
#define __AT32F435_437_WK_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/* includes -----------------------------------------------------------------------*/
#include "stdio.h"
#include "at32f435_437.h"

/* private includes -------------------------------------------------------------*/
/* add user code begin private includes */
#include "fog.h"
/* add user code end private includes */

/* exported types -------------------------------------------------------------*/
/* add user code begin exported types */

/* add user code end exported types */

/* exported constants --------------------------------------------------------*/
/* add user code begin exported constants */

/* add user code end exported constants */

/* exported macro ------------------------------------------------------------*/
/* add user code begin exported macro */

/* add user code end exported macro */

/* add user code begin dma define */
/* user can only modify the dma define value */
#define DMA1_CHANNEL1_BUFFER_SIZE   10
#define DMA1_CHANNEL1_MEMORY_BASE_ADDR   (uint32_t)gync_x_receive
//#define DMA1_CHANNEL1_PERIPHERAL_BASE_ADDR  0

#define DMA1_CHANNEL2_BUFFER_SIZE   1
#define DMA1_CHANNEL2_MEMORY_BASE_ADDR   (uint32_t)&command
//#define DMA1_CHANNEL2_PERIPHERAL_BASE_ADDR   0

#define DMA1_CHANNEL3_BUFFER_SIZE   10
#define DMA1_CHANNEL3_MEMORY_BASE_ADDR   (uint32_t)gync_y_receive
//#define DMA1_CHANNEL3_PERIPHERAL_BASE_ADDR   0

#define DMA1_CHANNEL4_BUFFER_SIZE   1
#define DMA1_CHANNEL4_MEMORY_BASE_ADDR   (uint32_t)&command
//#define DMA1_CHANNEL4_PERIPHERAL_BASE_ADDR   0

#define DMA1_CHANNEL5_BUFFER_SIZE   10
#define DMA1_CHANNEL5_MEMORY_BASE_ADDR   (uint32_t)gync_z_receive
//#define DMA1_CHANNEL5_PERIPHERAL_BASE_ADDR   0

#define DMA1_CHANNEL6_BUFFER_SIZE   1
#define DMA1_CHANNEL6_MEMORY_BASE_ADDR   (uint32_t)&command
//#define DMA1_CHANNEL6_PERIPHERAL_BASE_ADDR   0

#define DMA1_CHANNEL7_BUFFER_SIZE   sizeof(Fog_Transmit)
#define DMA1_CHANNEL7_MEMORY_BASE_ADDR   (uint32_t)&Fog_Transmit
//#define DMA1_CHANNEL7_PERIPHERAL_BASE_ADDR   0

#define DMA2_CHANNEL1_BUFFER_SIZE   4
#define DMA2_CHANNEL1_MEMORY_BASE_ADDR   (uint32_t)adc_xyz
//#define DMA2_CHANNEL1_PERIPHERAL_BASE_ADDR   0

//#define DMA2_CHANNEL2_BUFFER_SIZE   0
//#define DMA2_CHANNEL2_MEMORY_BASE_ADDR   0
//#define DMA2_CHANNEL2_PERIPHERAL_BASE_ADDR   0

//#define DMA2_CHANNEL3_BUFFER_SIZE   0
//#define DMA2_CHANNEL3_MEMORY_BASE_ADDR   0
//#define DMA2_CHANNEL3_PERIPHERAL_BASE_ADDR   0

#define DMA2_CHANNEL4_BUFFER_SIZE   1
#define DMA2_CHANNEL4_MEMORY_BASE_ADDR   (uint32_t)&adc_value
//#define DMA2_CHANNEL4_PERIPHERAL_BASE_ADDR   0

#define DMA2_CHANNEL5_BUFFER_SIZE   1
#define DMA2_CHANNEL5_MEMORY_BASE_ADDR   (uint32_t)&dac_value
//#define DMA2_CHANNEL5_PERIPHERAL_BASE_ADDR   0

//#define DMA2_CHANNEL6_BUFFER_SIZE   0
//#define DMA2_CHANNEL6_MEMORY_BASE_ADDR   0
//#define DMA2_CHANNEL6_PERIPHERAL_BASE_ADDR   0

#define DMA2_CHANNEL7_BUFFER_SIZE   21
#define DMA2_CHANNEL7_MEMORY_BASE_ADDR   (uint32_t)pid_transmit_receive
//#define DMA2_CHANNEL7_PERIPHERAL_BASE_ADDR   0
 
//#define EDMA_STREAM1_BUFFER_SIZE   0
//#define EDMA_STREAM1_MEMORY0_BASE_ADDR   0
//#define EDMA_STREAM1_PERIPHERAL_BASE_ADDR   0
//#define EDMA_STREAM1_MEMORY1_BASE_ADDR   0
//#define EDMA_STREAM1_LINK_LIST_POINTER   0
 
//#define EDMA_STREAM2_BUFFER_SIZE   0
//#define EDMA_STREAM2_MEMORY0_BASE_ADDR   0
//#define EDMA_STREAM2_PERIPHERAL_BASE_ADDR   0
//#define EDMA_STREAM2_MEMORY1_BASE_ADDR   0
//#define EDMA_STREAM2_LINK_LIST_POINTER   0
 
//#define EDMA_STREAM3_BUFFER_SIZE   0
//#define EDMA_STREAM3_MEMORY0_BASE_ADDR   0
//#define EDMA_STREAM3_PERIPHERAL_BASE_ADDR   0
//#define EDMA_STREAM3_MEMORY1_BASE_ADDR   0
//#define EDMA_STREAM3_LINK_LIST_POINTER   0
 
//#define EDMA_STREAM4_BUFFER_SIZE   0
//#define EDMA_STREAM4_MEMORY0_BASE_ADDR   0
//#define EDMA_STREAM4_PERIPHERAL_BASE_ADDR   0
//#define EDMA_STREAM4_MEMORY1_BASE_ADDR   0
//#define EDMA_STREAM4_LINK_LIST_POINTER   0
 
//#define EDMA_STREAM5_BUFFER_SIZE   0
//#define EDMA_STREAM5_MEMORY0_BASE_ADDR   0
//#define EDMA_STREAM5_PERIPHERAL_BASE_ADDR   0
//#define EDMA_STREAM5_MEMORY1_BASE_ADDR   0
//#define EDMA_STREAM5_LINK_LIST_POINTER   0
 
//#define EDMA_STREAM6_BUFFER_SIZE   0
//#define EDMA_STREAM6_MEMORY0_BASE_ADDR   0
//#define EDMA_STREAM6_PERIPHERAL_BASE_ADDR   0
//#define EDMA_STREAM6_MEMORY1_BASE_ADDR   0
//#define EDMA_STREAM6_LINK_LIST_POINTER   0
 
//#define EDMA_STREAM7_BUFFER_SIZE   0
//#define EDMA_STREAM7_MEMORY0_BASE_ADDR   0
//#define EDMA_STREAM7_PERIPHERAL_BASE_ADDR   0
//#define EDMA_STREAM7_MEMORY1_BASE_ADDR   0
//#define EDMA_STREAM7_LINK_LIST_POINTER   0
 
//#define EDMA_STREAM8_BUFFER_SIZE   0
//#define EDMA_STREAM8_MEMORY0_BASE_ADDR   0
//#define EDMA_STREAM8_PERIPHERAL_BASE_ADDR   0
//#define EDMA_STREAM8_MEMORY1_BASE_ADDR   0
//#define EDMA_STREAM8_LINK_LIST_POINTER   0
/* add user code end dma define */

/* Private defines -------------------------------------------------------------*/
#define LED_STAT_PIN    GPIO_PINS_13
#define LED_STAT_GPIO_PORT    GPIOC
#define GX_TX_PIN    GPIO_PINS_0
#define GX_TX_GPIO_PORT    GPIOA
#define GX_RX_PIN    GPIO_PINS_1
#define GX_RX_GPIO_PORT    GPIOA
#define FOG_TX_PIN    GPIO_PINS_2
#define FOG_TX_GPIO_PORT    GPIOA
#define FOG_RX_PIN    GPIO_PINS_3
#define FOG_RX_GPIO_PORT    GPIOA
#define AOUT_PIN    GPIO_PINS_0
#define AOUT_GPIO_PORT    GPIOB
#define SPI_SCK_PIN    GPIO_PINS_1
#define SPI_SCK_GPIO_PORT    GPIOB
#define GY_TX_PIN    GPIO_PINS_10
#define GY_TX_GPIO_PORT    GPIOB
#define GY_RX_PIN    GPIO_PINS_11
#define GY_RX_GPIO_PORT    GPIOB
#define I2C_SDA_PIN    GPIO_PINS_3
#define I2C_SDA_GPIO_PORT    GPIOH
#define CS_AZ_PIN    GPIO_PINS_12
#define CS_AZ_GPIO_PORT    GPIOB
#define SPI_MISO_PIN    GPIO_PINS_14
#define SPI_MISO_GPIO_PORT    GPIOB
#define MCLK_PIN    GPIO_PINS_8
#define MCLK_GPIO_PORT    GPIOA
#define SYNC_PIN    GPIO_PINS_9
#define SYNC_GPIO_PORT    GPIOA
#define CS_AY_PIN    GPIO_PINS_10
#define CS_AY_GPIO_PORT    GPIOA
#define CS_AX_PIN    GPIO_PINS_11
#define CS_AX_GPIO_PORT    GPIOA
#define DRL_PIN    GPIO_PINS_12
#define DRL_GPIO_PORT    GPIOA
#define I2C_SCK_PIN    GPIO_PINS_2
#define I2C_SCK_GPIO_PORT    GPIOH
#define GC_PIN    GPIO_PINS_15
#define GC_GPIO_PORT    GPIOA
#define GZ_TX_PIN    GPIO_PINS_6
#define GZ_TX_GPIO_PORT    GPIOB
#define GZ_RX_PIN    GPIO_PINS_7
#define GZ_RX_GPIO_PORT    GPIOB

/* exported functions ------------------------------------------------------- */
  /* system clock config. */
  void wk_system_clock_config(void);

  /* config periph clock. */
  void wk_periph_clock_config(void);

  /* nvic config. */
  void wk_nvic_config(void);

/* add user code begin exported functions */
	extern uint8_t 				command;
	extern uint8_t 				gync_x_receive[10];
	extern uint8_t 				gync_y_receive[10];
	extern uint8_t 				gync_z_receive[10];
	extern Fog_Transmit_t Fog_Transmit;
	extern uint8_t 				adc_xyz[4];
	extern uint16_t				adc_value;
	extern uint16_t				dac_value;
	extern uint8_t 				pid_transmit_receive[DMA2_CHANNEL7_BUFFER_SIZE];
/* add user code end exported functions */

#ifdef __cplusplus
}
#endif

#endif
