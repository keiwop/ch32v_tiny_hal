
#include <tiny_hal.h>
#include <tiny_hal/i2c.h>
#include <tiny_hal/hw/1602_i2c.h>
#include <stdio.h>

#define LED_PIN     (PC3)


void main(){
    pin_output(LED_PIN);
    char line1[16] = "Hello\0";
    char line2[16] = "World\0";
    uint32_t count = 0;

    while(1){
        pin_toggle(LED_PIN);

        lcd_init();
        
        lcd_move_cursor(0, 0);
        lcd_print(line1);
        
        lcd_move_cursor(1, 0);
        lcd_print(line2);
        
        delay_ms(500);
    }
}
