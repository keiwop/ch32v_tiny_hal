// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#include <tiny_hal/init.h>

// Global variable used by sprintf in various places
#ifdef ENABLE_PRINTF
	char printf_buf[PRINTF_BUF_SIZE];
#endif


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

    #ifdef ENABLE_UART
        uart_enable(UART_BAUDRATE);
    #endif

    #ifdef ENABLE_I2C
        i2c_enable();
    #endif

    #if defined(ENABLE_1602_I2C) || defined(ENABLE_1602)
		lcd16_init();
	#endif

    #ifdef ENABLE_MCO
        mco_enable();
    #endif
}
