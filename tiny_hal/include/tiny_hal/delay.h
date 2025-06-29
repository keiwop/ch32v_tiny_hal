// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef     __DELAY__
#define     __DELAY__

#include <stdint.h>
#include <tiny_hal/io.h>
#include <tiny_hal/macro.h>

#ifndef F_CPU
    #define F_CPU   (24000000UL)
#endif

#ifndef PROTO_TIMEOUT
    #define PROTO_TIMEOUT   (1000000UL)
#endif


#define delay_us(duration) 	delay_cycles((int32_t) ((F_CPU / 1000000) * duration))
#define delay_ms(duration) 	for(uint32_t i = 0; i < duration; ++i){ delay_us(1000); }


// Precision is ok and does not use any timer (and rdcycle is not implemented on this chip)
static inline void delay_cycles(int32_t cycles){
    while(cycles > 0){
        cycles -= 5;
        nop();
    }
}


// Wait until a specific bit in a register reaches the target value
// Returns 1 if a timeout occurs
static inline uint8_t wait_for_bit(uint32_t reg, uint8_t bit, uint8_t value){
    uint32_t counter = PROTO_TIMEOUT;
    while(counter-- > 0){
        if(check_bit(reg, bit) >> bit == value){
            return 0;
        }
    }
    return 1;
}


#endif // __DELAY__
