// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#include <tiny_hal.h>
#include <tiny_hal/uart.h>
#include <stdio.h>

#define LED_PIN     (PC3)


void main(){
    pin_output(LED_PIN);
    char str[16] = "Hello\0";
    uint32_t count = 0;

    while(1){
        pin_toggle(LED_PIN);
        // uart_send_byte(uart_recv_byte());

        // uart_read(str, 16);
        // uart_print(str);
        // uart_print("\n");

        uart_print(str);
        uart_printf(" World: %ld\r\n", count++);
        // delay_ms(5);
    }
}
