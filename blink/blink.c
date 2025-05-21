#include "tiny_hal.h"


#define LED_PIN     (PC3)


void main(){

    pin_output(LED_PIN);

    while(1){
        pin_toggle(LED_PIN);
        delay_ms(400);
    }
}
