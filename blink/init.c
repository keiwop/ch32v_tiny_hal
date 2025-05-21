
#include "init.h"


void __init__(){
    // Disable HB clock prescaler
    reg_ptr(RCC_CFGR0) &= ~(0b1111 << HPRE);
    
    // Enable peripheral clocks
    // TODO: Don't enable all of them?
    sbi(RCC_APB2PCENR, IOPAEN);
    sbi(RCC_APB2PCENR, IOPCEN);
    sbi(RCC_APB2PCENR, IOPDEN);
    
    // enable_mco_output();
}
