# Copyright (C): 2025 - keiwop
# SPDX-License-Identifier: GPL-3.0-or-later

PROGRAM     := blink_minimal
MCU         := ch32v003
PROGRAMMER  := minichlink
BOOT        := minimal


ASM         :=
SRC         := blink_minimal.c

DEFINES     := -DF_CPU=24000000UL


PROG_PATH   := $(realpath .)
.DEFAULT_GOAL := all

%:
	$(MAKE) -C ../.. $@ \
        PROGRAM="$(PROGRAM)" MCU="$(MCU)" BOOT="$(BOOT)" PROGRAMMER="$(PROGRAMMER)" \
        PROG_PATH="$(PROG_PATH)" PROG_ASM="$(ASM)" PROG_SRC="$(SRC)" DEFINES="$(DEFINES)"
