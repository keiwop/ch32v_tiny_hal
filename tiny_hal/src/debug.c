
#include <tiny_hal/debug.h>


// Global variable used by logging functions
#if LOG_LEVEL > 0
	char log_buf[LOG_BUF_SIZE];
#endif


// Exposes system clocks to the MCO pin (PC4 on ch32v003)
// Pin should be push-pull multiplexed output
void mco_enable(){
    gpio_clear_cfg(PIN_MCO);
    gpio_out_mpp_50MHz(PIN_MCO);
    reg_ptr(RCC_CFGR0) &= ~(0b111 << RCC_MCO);
    reg_ptr(RCC_CFGR0) |= (0b100 << RCC_MCO);
}


void blink_led(uint8_t pin, uint8_t nb_blink){
    if(!nb_blink){ return; }
    
    pin_output(pin);

    while(nb_blink--){
        pin_set(pin);
        delay_ms(DBG_BLINK_DELAY);
        pin_clear(pin);
        delay_ms(DBG_BLINK_DELAY);
    }
}
