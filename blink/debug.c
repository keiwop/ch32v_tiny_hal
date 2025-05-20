
#include "debug.h"


void enable_mco_output(){
    gpio_clear(MCO_PIN);
    gpio_ptr(GPIO_CFGLR, MCO_PIN) |= 0b1011 << ((MCO_PIN % 8) * 4);
    reg_ptr(RCC_CFGR0) &= ~(0b111 << MCO);
    reg_ptr(RCC_CFGR0) |= (0b100 << MCO);
}
