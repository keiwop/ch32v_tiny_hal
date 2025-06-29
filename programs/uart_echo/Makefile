# Copyright (C): 2025 - keiwop
# SPDX-License-Identifier: GPL-3.0-or-later

PROGRAM     := uart_echo
MCU         := ch32v003
PROGRAMMER  := minichlink
BOOT        := init


ASM         :=
SRC         := uart_echo.c

DEFINES     := -DF_CPU=24000000UL -DENABLE_UART -DUART_BAUDRATE=115200 -DENABLE_PRINTF -DPRINTF_BUF_SIZE=80


PROG_PATH   := $(realpath .)
.DEFAULT_GOAL := all

%:
	$(MAKE) -C ../.. $@ \
        PROGRAM="$(PROGRAM)" MCU="$(MCU)" BOOT="$(BOOT)" PROGRAMMER="$(PROGRAMMER)" \
        PROG_PATH="$(PROG_PATH)" PROG_ASM="$(ASM)" PROG_SRC="$(SRC)" DEFINES="$(DEFINES)"
