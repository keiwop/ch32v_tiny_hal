
#include <tiny_hal/init.h>

// Called before main from boot/$(MCU)_init.s
void __init__(){
    // Disable HB clock prescaler
    reg_ptr(RCC_CFGR0) &= ~(0b1111 << HPRE);
    
    // Enable peripheral clocks
    // TODO: Don't enable all of them?
    sbi(RCC_APB2PCENR, IOPAEN);
    sbi(RCC_APB2PCENR, IOPCEN);
    sbi(RCC_APB2PCENR, IOPDEN);
    sbi(RCC_APB2PCENR, AFIOEN);

    #ifdef ENABLE_I2C
        i2c_enable();
    #endif
    
    #ifdef ENABLE_1602_I2C
		lcd_init();
	#endif

    #ifdef ENABLE_MCO
        mco_enable();
    #endif
}
