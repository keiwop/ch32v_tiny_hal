// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#include <tiny_hal.h>

#define LED_PIN     (PC3)


void main(){
    pin_output(LED_PIN);

    while(1){
        pin_toggle(LED_PIN);
        delay_ms(500);
    }
}
