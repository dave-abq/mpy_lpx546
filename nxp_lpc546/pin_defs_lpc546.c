#include "py/obj.h"
#include "pin.h"

// Returns the pin mode. This value returned by this macro should be one of:
// GPIO_MODE_INPUT, GPIO_MODE_OUTPUT_PP, GPIO_MODE_OUTPUT_OD,
// GPIO_MODE_AF_PP, GPIO_MODE_AF_OD, or GPIO_MODE_ANALOG.

uint32_t pin_get_mode(const pin_obj_t *pin) {
	IOCON_Type *pIOCON = IOCON;
	uint32_t t = pIOCON->PIO[pin->port][pin->pin];
	t = t & (7 << 6); // extract pull settings field
	return t;

}

// Returns the pin pullup/pulldown. The value returned by this macro should
// be one of GPIO_NOPULL, GPIO_PULLUP, or GPIO_PULLDOWN.

uint32_t pin_get_pull(const pin_obj_t *pin) {
	IOCON_Type *pIOCON = IOCON;
	uint32_t t = pIOCON->PIO[pin->port][pin->pin];
	t = t & (3 << 4); // extract pull settings field
	return t;
}

// Returns the af (alternate function) index currently set for a pin.

uint32_t pin_get_af(const pin_obj_t *pin) {
	IOCON_Type *pIOCON = IOCON;
	uint32_t t = pIOCON->PIO[pin->port][pin->pin];
	t = t & (15); // extract pull settings field
	return t;

}

