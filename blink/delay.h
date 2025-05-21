
#ifndef     __DELAY__
#define     __DELAY__

#include <stdint.h>

#define nop()   __asm__ volatile ("nop")
#define F_CPU   (24000000UL)
#define delay_us(duration) 	delay_cycles((int32_t) ((F_CPU / 1000000) * duration))
#define delay_ms(duration) 	for(uint32_t i = 0; i < duration; ++i){ delay_us(1000); }


// Precision is ok and does not use any timer (and rdcycle is not implemented on this chip)
static inline void delay_cycles(int32_t cycles){
    while(cycles > 0){
        cycles -= 5;
        nop();
    }
}


#endif // __DELAY__
