// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#include <tiny_hal.h>


void main(){
    for(uint8_t i  = 0; i < 32; ++i){
        if((i == PD1) || (i == PA0) || (i > PA2 && i < PC0)){ continue; }
        pin_output(i);
        delay_ms(1);
    }

    while(1){
        for(uint8_t i  = 0; i < 32; ++i){
            if((i == PD1) || (i == PA0) || (i > PA2 && i < PC0)){ continue; }
            pin_toggle(i);
        }
        delay_ms(500);
    }
}
