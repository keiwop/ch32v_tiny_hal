// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef     __UART__
#define     __UART__

#include <tiny_hal/registers.h>
#include <tiny_hal/io.h>
#include <tiny_hal/delay.h>
#include <tiny_hal/debug.h>


// UART pins should be defined as TX multiplexed push-pull output and RX input pull-up
#ifndef PIN_UART_TX
    #define PIN_UART_TX     (PD5)
#endif
#ifndef PIN_UART_RX
    #define PIN_UART_RX     (PD6)
#endif


#ifndef UART_BAUDRATE
    #define UART_BAUDRATE   (115200)
#endif

#define UART_MANTISSA       ((F_CPU / UART_BAUDRATE) / 16)
#define UART_FRACTION       ((F_CPU / UART_BAUDRATE) % 16)


typedef enum: uint8_t{
    UART_EOK,
    UART_ETXE,
    UART_ECOMPLETE,
    UART_ERXNE,
    UART_EOVERLOAD,
    UART_EFRAME,
    UART_EPARITY,
    UART_EUNKN,
} uart_t;


#ifdef ENABLE_PRINTF
    #define uart_printf(...)    sprintf(printf_buf, __VA_ARGS__); uart_print(printf_buf)
#endif

void uart_reset();
void uart_enable();
uart_t uart_send_byte(uint8_t data);
uart_t uart_send_nbytes(uint8_t *data, uint8_t nbytes);
uart_t uart_print(char *str);
uint16_t uart_recv_byte(void);
uint16_t uart_read(char *buf, uint8_t max_len);
void uart_flush(void);


#endif // __UART__
