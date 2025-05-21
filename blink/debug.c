
#include "debug.h"


void enable_mco_output(){
    gpio_clear_cfg(MCO_PIN);
    gpio_out_mpp_50MHz(MCO_PIN);
    reg_ptr(RCC_CFGR0) &= ~(0b111 << MCO);
    reg_ptr(RCC_CFGR0) |= (0b100 << MCO);
}
