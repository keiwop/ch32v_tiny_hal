
#include <tiny_hal.h>

#define LED_PIN     (PC3)


void main(){
    sbi(RCC_APB2PCENR, IOPCEN);     // Enable PORTC clock.
    (gpio_ptr(GPIO_CFGLR, LED_PIN) = (0b0001 << ((LED_PIN % 8) * 4)));  // Clear and set the pin config by overwriting the whole register

    while(1){
        pin_toggle(LED_PIN);    // Slower than pin_set/pin_clear but takes less space
        for(uint32_t i = 42000; i > 0; i--){    // Do not use volatile var, let the compiler optimize the loop
            nop();  // The nop is volatile instruction anyway so there's still a loop
        }
    }
}
