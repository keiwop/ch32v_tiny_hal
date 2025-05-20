
#ifndef     __DELAY__
#define     __DELAY__

#include <stdint.h>


#define F_CPU    (24000000UL)


static inline void delay_cycles(uint32_t cycles){
    __asm__ volatile(
        "loop:              \n\t"
        " nop               \n\t"
        " addi %0, %0, -3   \n\t"
        " bgez %0, loop     \n\t"
        : "+r"(cycles)
        :
        : "x4"
    );
}

#define nop()               __asm__ volatile ("nop")
// #define delay_cycles(n) 	for(uint32_t i = 0; i < n; ++i){ nop(); }
#define delay_ms(duration) 	delay_cycles(((F_CPU / 1000) * duration))
#define delay_us(duration) 	delay_cycles(((F_CPU / 1000000) * duration))
#define delay_ns(duration) 	delay_cycles((((F_CPU / 1000) * duration) / 1000000))


// uint8_t idelay_ms(uint16_t duration);
// void delay_us_var(uint16_t duration);

#endif // __DELAY__
