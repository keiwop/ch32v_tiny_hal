// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef 	__INIT__
#define 	__INIT__

#include <tiny_hal/registers.h>
#include <tiny_hal/io.h>
#include <tiny_hal/macro.h>
#include <tiny_hal/delay.h>
#include <tiny_hal/debug.h>
#include <tiny_hal/uart.h>
#include <tiny_hal/i2c.h>
#include <tiny_hal/hw/1602_i2c.h>

#ifndef PRINTF_BUF_SIZE
    #define PRINTF_BUF_SIZE     (80)
#endif

#ifdef ENABLE_PRINTF
    #include <stdio.h>
    extern char printf_buf[PRINTF_BUF_SIZE];
#endif


void __init__();


#endif // __INIT__
