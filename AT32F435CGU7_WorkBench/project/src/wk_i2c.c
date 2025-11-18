/* add user code begin Header */
/**
  **************************************************************************
  * @file     wk_i2c.c
  * @brief    work bench config program
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
#include "wk_i2c.h"

/* add user code begin 0 */
#define I2C_TIMEOUT                      0x000FFFF

i2c_handle_type hi2cx;
uint8_t i2c_rx_buf[2];
uint16_t i2c_temperature_temp;
float i2c_temperature;

void i2c_lowlevel_init(i2c_handle_type* hi2c)
{
  gpio_init_type gpio_init_struct;
	
  gpio_default_para_init(&gpio_init_struct);

  /* configure the SCL pin */
  gpio_pin_mux_config(GPIOH, GPIO_PINS_SOURCE2, GPIO_MUX_4);
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_OPEN_DRAIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_pins = GPIO_PINS_2;
  gpio_init(GPIOH, &gpio_init_struct);

  /* configure the SDA pin */
  gpio_pin_mux_config(GPIOH, GPIO_PINS_SOURCE3, GPIO_MUX_4);
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_OPEN_DRAIN;
  gpio_init_struct.gpio_pull = GPIO_PULL_UP;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init_struct.gpio_pins = GPIO_PINS_3;
  gpio_init(GPIOH, &gpio_init_struct); 
	
	hi2c->dma_tx_channel = DMA2_CHANNEL2;
	hi2c->dma_rx_channel = DMA2_CHANNEL3;

	dma_reset(hi2c->dma_tx_channel);
	dma_reset(hi2c->dma_rx_channel);

	dma_default_para_init(&hi2c->dma_init_struct);
	hi2c->dma_init_struct.peripheral_inc_enable    = FALSE;
	hi2c->dma_init_struct.memory_inc_enable        = TRUE;
	hi2c->dma_init_struct.peripheral_data_width    = DMA_PERIPHERAL_DATA_WIDTH_BYTE;
	hi2c->dma_init_struct.memory_data_width        = DMA_MEMORY_DATA_WIDTH_BYTE;
	hi2c->dma_init_struct.loop_mode_enable         = FALSE;
	hi2c->dma_init_struct.priority                 = DMA_PRIORITY_LOW;
	hi2c->dma_init_struct.direction                = DMA_DIR_MEMORY_TO_PERIPHERAL;

	dma_init(hi2c->dma_tx_channel, &hi2c->dma_init_struct);
	dma_init(hi2c->dma_rx_channel, &hi2c->dma_init_struct);
	
	dmamux_init(DMA2MUX_CHANNEL2, DMAMUX_DMAREQ_ID_I2C2_TX);
  dmamux_init(DMA2MUX_CHANNEL3, DMAMUX_DMAREQ_ID_I2C2_RX);
	
	dmamux_enable(DMA2, TRUE);
	
  /* config i2c */
  i2c_init(hi2c->i2cx, 0, 0xC0F03030);
  i2c_own_address1_set(hi2c->i2cx, I2C_ADDRESS_MODE_7BIT, 0x0);
  i2c_ack_enable(I2C2, TRUE);
  i2c_clock_stretch_enable(I2C2, TRUE);
  i2c_general_call_enable(I2C2, FALSE);
}

float decode_tmp117(uint16_t hex_data) {
  return (int16_t)hex_data / 128.0f;
}

void i2c_receive_data(){
  /* start the request reception process */
  i2c_master_receive_dma(&hi2cx, 0x0090, i2c_rx_buf, 2, I2C_TIMEOUT);
}
/* add user code end 0 */

/**
  * @brief  init i2c2 function.
  * @param  none
  * @retval none
  */
void wk_i2c2_init(void)
{
  /* add user code begin i2c2_init 0 */
	hi2cx.i2cx = I2C2;
  i2c_config(&hi2cx);
  /* add user code end i2c2_init 0 */
}

/* add user code begin 1 */

/* add user code end 1 */
