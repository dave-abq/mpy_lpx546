#define MICROPY_HW_BOARD_NAME       "LPX54608"
#define MICROPY_HW_MCU_NAME         "LPC54608"

#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_HAS_SDCARD       (0)
#define MICROPY_HW_HAS_LCD          (0)
#define MICROPY_HW_ENABLE_RNG       (0)
#define MICROPY_HW_ENABLE_RTC       (0)
#define MICROPY_HW_ENABLE_CTMR      (0)
#define MICROPY_HW_ENABLE_SERVO     (0)
#define MICROPY_HW_ENABLE_DAC       (0)
#define MICROPY_HW_ENABLE_CAN       (0)

// XTAL is 12MHz

// The pyboard has a 32kHz crystal for the RTC
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (1)
/*
// UART config
#define MICROPY_HW_UART1_NAME   "XB"
#define MICROPY_HW_UART1_TX     (pin_B6)
#define MICROPY_HW_UART1_RX     (pin_B7)
#define MICROPY_HW_UART2_TX     (pin_A2)
#define MICROPY_HW_UART2_RX     (pin_A3)
#define MICROPY_HW_UART2_RTS    (pin_A1)
#define MICROPY_HW_UART2_CTS    (pin_A0)
#define MICROPY_HW_UART3_NAME   "YB"
#define MICROPY_HW_UART3_TX     (pin_B10)
#define MICROPY_HW_UART3_RX     (pin_B11)
#define MICROPY_HW_UART3_RTS    (pin_B14)
#define MICROPY_HW_UART3_CTS    (pin_B13)
#define MICROPY_HW_UART4_NAME   "XA"
#define MICROPY_HW_UART4_TX     (pin_A0)
#define MICROPY_HW_UART4_RX     (pin_A1)
#define MICROPY_HW_UART6_NAME   "YA"
#define MICROPY_HW_UART6_TX     (pin_C6)
#define MICROPY_HW_UART6_RX     (pin_C7)

// I2C busses
#define MICROPY_HW_I2C1_NAME "X"
#define MICROPY_HW_I2C1_SCL (pin_B6)
#define MICROPY_HW_I2C1_SDA (pin_B7)
#define MICROPY_HW_I2C2_NAME "Y"
#define MICROPY_HW_I2C2_SCL (pin_B10)
#define MICROPY_HW_I2C2_SDA (pin_B11)

// SPI busses
#define MICROPY_HW_SPI1_NAME "X"
#define MICROPY_HW_SPI1_NSS  (pin_A4) // X5
#define MICROPY_HW_SPI1_SCK  (pin_A5) // X6
#define MICROPY_HW_SPI1_MISO (pin_A6) // X7
#define MICROPY_HW_SPI1_MOSI (pin_A7) // X8
#define MICROPY_HW_SPI2_NAME "Y"
#define MICROPY_HW_SPI2_NSS  (pin_B12) // Y5
#define MICROPY_HW_SPI2_SCK  (pin_B13) // Y6
#define MICROPY_HW_SPI2_MISO (pin_B14) // Y7
#define MICROPY_HW_SPI2_MOSI (pin_B15) // Y8

// CAN busses
#define MICROPY_HW_CAN1_NAME "YA" // CAN1 on RX,TX = Y3,Y4 = PB8,PB9
#define MICROPY_HW_CAN2_NAME "YB" // CAN2 on RX,TX = Y5,Y6 = PB12,PB13
*/
// USRSW has no pullup or pulldown, and pressing the switch makes the input go low
#define MICROPY_HW_USRSW_PIN        (pin_33)
#define MICROPY_HW_USRSW_PULL       (1) //(GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (2) //(GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// The LPX54608 has 3 LEDs
#define MICROPY_HW_LED1             (pin_314) // red
#define MICROPY_HW_LED2             (pin_33) // green
#define MICROPY_HW_LED3             (pin_22) // yellow

#define MICROPY_HW_LED1_PWM         { CTIMER3, 1, IOCON_FUNC3}
#define MICROPY_HW_LED3_PWM         { CTIMER1, 1, IOCON_FUNC4}
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))

// SD card detect switch
#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_33)
#define MICROPY_HW_SDCARD_DETECT_PULL       (1) // (GPIO_PULLUP)
#define MICROPY_HW_SDCARD_DETECT_PRESENT    (2) // (GPIO_PIN_RESET)

// USB config
// #define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
// #define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)

// MMA accelerometer config
// #define MICROPY_HW_MMA_AVDD_PIN     (pin_B5)
