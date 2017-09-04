/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

// This file contains pin definitions that are specific to the stmhal port.
// This file should only ever be #included by pin.h and not directly.

enum {
  PORT_0 = 0,
  PORT_1,
  PORT_2,
  PORT_3,
  PORT_4,
  PORT_5,
  PORT_6,
  PORT_7,
  PORT_8,
  PORT_9,
};

#define GPIO0   GPIO
#define GPIO1   GPIO
#define GPIO2   GPIO
#define GPIO3   GPIO
#define GPIO4   GPIO
#define GPIO5   GPIO

enum {
  AF_FN_GPIO,
  AF_FN_TIM,
  AF_FN_I2C,
  AF_FN_USART,
  AF_FN_UART = AF_FN_USART,
  AF_FN_SPI,
  AF_FN_I2S,
  AF_FN_SDMMC,
  AF_FN_CTIMER,
};

enum {
  AF_PIN_TYPE_GPIO_PIN0,
  AF_PIN_TYPE_GPIO_PIN1,
  AF_PIN_TYPE_GPIO_PIN2,
  AF_PIN_TYPE_GPIO_PIN3,
  AF_PIN_TYPE_GPIO_PIN4,
  AF_PIN_TYPE_GPIO_PIN5,
  AF_PIN_TYPE_GPIO_PIN6,
  AF_PIN_TYPE_GPIO_PIN7,
  AF_PIN_TYPE_GPIO_PIN8,
  AF_PIN_TYPE_GPIO_PIN9,
  AF_PIN_TYPE_GPIO_PIN10,
  AF_PIN_TYPE_GPIO_PIN11,
  AF_PIN_TYPE_GPIO_PIN12,
  AF_PIN_TYPE_GPIO_PIN13,
  AF_PIN_TYPE_GPIO_PIN14,
  AF_PIN_TYPE_GPIO_PIN15,
  AF_PIN_TYPE_GPIO_PIN16,
  AF_PIN_TYPE_GPIO_PIN17,
  AF_PIN_TYPE_GPIO_PIN18,
  AF_PIN_TYPE_GPIO_PIN19,
  AF_PIN_TYPE_GPIO_PIN20,
  AF_PIN_TYPE_GPIO_PIN21,
  AF_PIN_TYPE_GPIO_PIN22,
  AF_PIN_TYPE_GPIO_PIN23,
  AF_PIN_TYPE_GPIO_PIN24,
  AF_PIN_TYPE_GPIO_PIN25,
  AF_PIN_TYPE_GPIO_PIN26,
  AF_PIN_TYPE_GPIO_PIN27,
  AF_PIN_TYPE_GPIO_PIN28,
  AF_PIN_TYPE_GPIO_PIN29,
  AF_PIN_TYPE_GPIO_PIN30,
  AF_PIN_TYPE_GPIO_PIN31,

  AF_PIN_TYPE_I2C_SDA = 0,
  AF_PIN_TYPE_I2C_SCL,

  AF_PIN_TYPE_USART_TX = 0,
  AF_PIN_TYPE_USART_RX,
  AF_PIN_TYPE_USART_CTS,
  AF_PIN_TYPE_USART_RTS,
  AF_PIN_TYPE_USART_CK,

  AF_PIN_TYPE_SPI_MOSI = 0,
  AF_PIN_TYPE_SPI_MISO,
  AF_PIN_TYPE_SPI_SCK,
  AF_PIN_TYPE_SPI_NSS,

  AF_PIN_TYPE_I2S_CK = 0,
  AF_PIN_TYPE_I2S_MCK,
  AF_PIN_TYPE_I2S_SD,
  AF_PIN_TYPE_I2S_WS,
  AF_PIN_TYPE_I2S_EXTSD,

  AF_PIN_TYPE_CTIMER_MAT0,
  AF_PIN_TYPE_CTIMER_MAT1,
  AF_PIN_TYPE_CTIMER_MAT2,
  AF_PIN_TYPE_CTIMER_MAT3,
  AF_PIN_TYPE_CTIMER_CAP0,
  AF_PIN_TYPE_CTIMER_CAP1,
  AF_PIN_TYPE_CTIMER_CAP2,
  AF_PIN_TYPE_CTIMER_CAP3,

  AF_PIN_TYPE_SDMMC_CK = 0,
  AF_PIN_TYPE_SDMMC_CMD,
  AF_PIN_TYPE_SDMMC_D0,
  AF_PIN_TYPE_SDMMC_D1,
  AF_PIN_TYPE_SDMMC_D2,
  AF_PIN_TYPE_SDMMC_D3,
};

enum {
  PIN_ADC1  = (1 << 0),
  PIN_ADC2  = (1 << 1),
  PIN_ADC3  = (1 << 2),
};

