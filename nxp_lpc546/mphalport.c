#include <string.h>

#include "py/mpstate.h"
#include "py/runtime.h"
#include "py/mperrno.h"
#include "py/mphal.h"
#include "usb_app.h"
#include "uart.h"
#include "fsl_gpio.h"
#include "fsl_iocon.h"
#include "fsl_debug_console.h"
bool mp_hal_ticks_cpu_enabled = false;

// this table converts from HAL_StatusTypeDef to POSIX errno
const byte mp_hal_status_to_errno_table[4] = {
    [HAL_OK] = 0,
    [HAL_ERROR] = MP_EIO,
    [HAL_BUSY] = MP_EBUSY,
    [HAL_TIMEOUT] = MP_ETIMEDOUT,
};

NORETURN void mp_hal_raise(HAL_StatusTypeDef status) {
    mp_raise_OSError(mp_hal_status_to_errno_table[status]);
}

int mp_hal_stdin_rx_chr(void) {
	int c;
	for (;;) {
		c = DbgConsole_Getchar();
		if (c != -1)
			return c;
#ifdef USE_HOST_MODE
        pyb_usb_host_process();
        int c = pyb_usb_host_get_keyboard();
        if (c != 0) {
            return c;
        }
#endif

		/* rocky ignore 
        byte c;
        if (usb_vcp_recv_byte(&c) != 0) {
            return c;
        } else if (MP_STATE_PORT(pyb_stdio_uart) != NULL && uart_rx_any(MP_STATE_PORT(pyb_stdio_uart))) {
            return uart_rx_char(MP_STATE_PORT(pyb_stdio_uart));
        }
        */ 
        MICROPY_EVENT_POLL_HOOK
    }
}

void mp_hal_stdout_tx_str(const char *str) {
    mp_hal_stdout_tx_strn(str, strlen(str));
}

void mp_hal_stdout_tx_strn(const char *str, size_t len) {
	uint32_t i;
	for(i=0; i<len; i++) {
		DbgConsole_Putchar(str[i]);
	}
	/* rocky ignore
    if (MP_STATE_PORT(pyb_stdio_uart) != NULL) {
        uart_tx_strn(MP_STATE_PORT(pyb_stdio_uart), str, len);
    }
#if 0 && defined(USE_HOST_MODE) && MICROPY_HW_HAS_LCD
    lcd_print_strn(str, len);
#endif
    if (usb_vcp_is_enabled()) {
        usb_vcp_send_strn(str, len);
    }
    */
}

void mp_hal_stdout_tx_strn_cooked(const char *str, size_t len) {
	for (const char *top = str + len; str < top; str++) {
		if (*str == '\n') {
			DbgConsole_Putchar('\r');
		}
		DbgConsole_Putchar(*str);
	}


	/* rocky ignore
    // send stdout to UART and USB CDC VCP
    if (MP_STATE_PORT(pyb_stdio_uart) != NULL) {
        uart_tx_strn_cooked(MP_STATE_PORT(pyb_stdio_uart), str, len);
    }
    if (usb_vcp_is_enabled()) {
        usb_vcp_send_strn_cooked(str, len);
    }
    */
}

void mp_hal_ticks_cpu_enable(void) {
    if (!mp_hal_ticks_cpu_enabled) {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        #if defined(__CORTEX_M) && __CORTEX_M == 7
        // on Cortex-M7 we must unlock the DWT before writing to its registers
        DWT->LAR = 0xc5acce55;
        #endif
        DWT->CYCCNT = 0;
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
        mp_hal_ticks_cpu_enabled = true;
    }
}

void mp_hal_gpio_clock_enable(uint32_t portNum) {
	SYSCON_Type *pSysCon = SYSCON;
	if (portNum < 4) {
		pSysCon->AHBCLKCTRLSET[0] = portNum + 14;  // GPIO 0,1,2,3
	} else {
		pSysCon->AHBCLKCTRLSET[2] = portNum + 7;  // GPIO 4,5
	}
}

void mp_hal_pin_config(const pin_obj_t *pin_obj, uint32_t mode, uint32_t pull, uint32_t alt) {
    mp_hal_gpio_clock_enable(pin_obj->port);
	CLOCK_EnableClock(kCLOCK_Iocon);
	
	IOCON_PinMuxSet(IOCON, pin_obj->port, pin_obj->pin, alt | pull | mode);
}

bool mp_hal_pin_config_alt(mp_hal_pin_obj_t pin, uint32_t mode, uint32_t pull, uint8_t fn, uint8_t unit) {
    const pin_af_obj_t *af = pin_find_af(pin, fn, unit);
    if (af == NULL) {
        return false;
    }
    mp_hal_pin_config(pin, mode, pull, af->idx);
    return true;
}
