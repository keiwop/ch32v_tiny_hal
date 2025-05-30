// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef 	__DEBUG__
#define 	__DEBUG__

#include <stdint.h>
#include <tiny_hal/io.h>
#include <tiny_hal/delay.h>

// TODO: add flags

#define PIN_MCO             (PC4)
#define PIN_LED_BOARD       (PC3)
#define DBG_BLINK_DELAY     (300)
#define lh()                pin_set(PIN_LED_BOARD)
#define ll()                pin_clear(PIN_LED_BOARD)
#define dbg(nb_blink)       blink_led(PIN_LED_BOARD, nb_blink); delay_ms(200)


#ifndef LOG_LEVEL
    #define LOG_LEVEL       (42)
#endif

#ifndef LOG_BUF_SIZE
    #define LOG_BUF_SIZE    (80)
#endif


#if LOG_LEVEL > 0
    #include <stdio.h>

    // #include <tinylib/uart.h>
    // #define log_s(lvl, ...)     if(LOG_LEVEL >= lvl){ sprintf(log_buf, __VA_ARGS__); uart_print(log_buf); }

    #if defined(ENABLE_1602_I2C) || defined(ENABLE_1602)
        #include <tiny_hal/hw/1602_i2c.h>
        #define log_l(lvl, ...) if(LOG_LEVEL >= lvl){ sprintf(log_buf, __VA_ARGS__); lcd16_clear(); lcd16_print(log_buf); }
    #else
        #define log_l(...)      nop()
    #endif

    extern char log_buf[LOG_BUF_SIZE];

#else // Logging disabled
    #define log_s(...)          nop()
    #define log_l(...)          nop()
    #define debug()             nop()

#endif // LOG_LEVEL > 0


void mco_enable();
void blink_led(uint8_t pin, uint8_t nb_blink);

#endif // __DEBUG__
