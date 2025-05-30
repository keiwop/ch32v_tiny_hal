// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#include <tiny_hal.h>
#include <tiny_hal/i2c.h>
#include <tiny_hal/hw/1602_i2c.h>
#include <stdio.h>

#define LED_PIN     (PC3)


void main(){
    pin_output(LED_PIN);
    char line1[16] = "Hello\0";
    // char line2[16] = "World\0";
    uint32_t count = 0;
    
    while(1){
        pin_toggle(LED_PIN);
        
        lcd16_move_cursor(0, 0);
        lcd16_print(line1);
        
        lcd16_move_cursor(0, 1);
        lcd16_printf("%ld", count++);
        // lcd16_print(line2);
        
        delay_ms(5);
    }
}
