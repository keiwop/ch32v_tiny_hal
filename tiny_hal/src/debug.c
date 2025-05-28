
#include <tiny_hal/debug.h>


void mco_enable(){
    gpio_clear_cfg(MCO_PIN);
    gpio_out_mpp_50MHz(MCO_PIN);
    reg_ptr(RCC_CFGR0) &= ~(0b111 << MCO);
    reg_ptr(RCC_CFGR0) |= (0b100 << MCO);
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
