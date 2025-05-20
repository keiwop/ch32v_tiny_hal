// #include <stdint.h>
// #include <stdio.h>
#include "tiny_hal.h"


#define LED_PIN     (PC3)


void main(){

    pin_output(LED_PIN);
    // *((volatile uint32_t *) 0x40011000) &= ~(0b1111 << 12);
    // *((volatile uint32_t *) 0x40011000) |= (0b0001 << 12);
    while(1){
        // for(volatile uint32_t i = 15000; i > 0; i--);
        pin_toggle(LED_PIN);
        delay_ms(500);
    }
}
