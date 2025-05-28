
#ifndef 	__DEBUG__
#define 	__DEBUG__

#include <stdint.h>
#include <tiny_hal/io.h>
#include <tiny_hal/delay.h>

// TODO: add flags

#define MCO_PIN             (PC4)
#define DBG_BLINK_DELAY     (300)
#define dbg(nb_blink)       blink_led(PC3, nb_blink); delay_ms(200)

// Exposes different clocks to the MCO pin (PC4)
// Pin should be push-pull multiplexed output
void mco_enable();
void blink_led(uint8_t pin, uint8_t nb_blink);

#endif // __DEBUG__
