# Copyright (C): 2025 - keiwop
# SPDX-License-Identifier: GPL-3.0-or-later


# Target
PROGRAM     ?= blink
MCU         ?= ch32v003
BOOT        ?= init
PROGRAMMER  ?= minichlink
PROG_PATH   ?= programs/blink

# Toolchain
TOOLCHAIN   := riscv32-unknown-elf-
CC 			:= $(TOOLCHAIN)gcc
AS          := $(TOOLCHAIN)as
LD          := $(TOOLCHAIN)ld
OBJCOPY     := $(TOOLCHAIN)objcopy
OBJDUMP     := $(TOOLCHAIN)objdump
SIZE        := $(TOOLCHAIN)size
READELF     := $(TOOLCHAIN)readelf

# Flags overview in README
CFLAGS      := -march=rv32ec_zicsr -mabi=ilp32e -Wall -ffreestanding -MMD --specs=nano.specs
OPTIMIZE    := -Os -ffunction-sections -fdata-sections -msmall-data-limit=8
ASFLAGS     := -x assembler-with-cpp
LDFLAGS     := -nostartfiles -Tld/$(MCU).ld -Wl,-gc-sections,--print-gc-sections -Wl,--relax,--relax-gp

INCLUDES    ?= -Itiny_hal/include
DEFINES 	?= 

BUILD       ?= build


PROG_REL := $(shell realpath --relative-to $(realpath .) $(PROG_PATH))

ASM := $(foreach prog, $(PROG_ASM), $(PROG_REL)/$(prog))
ASM += \
    boot/$(MCU)_$(BOOT).s

SRC := $(foreach prog, $(PROG_SRC), $(PROG_REL)/$(prog))
SRC += \
    tiny_hal/src/debug.c \
    tiny_hal/src/init.c \
    tiny_hal/src/i2c.c \
    tiny_hal/src/hw/1602_i2c.c

C_OBJ := $(patsubst %.c, $(BUILD)/%.o, $(SRC))
S_OBJ := $(patsubst %.s, $(BUILD)/%.o, $(ASM))
OBJ := $(C_OBJ) $(S_OBJ)

$(info )
$(info ASM = $(ASM))
$(info SRC = $(SRC))
$(info OBJ = $(OBJ))
$(info )

DEPFILES := $(C_OBJ:.o=.d)
-include $(DEPFILES)


ELF := $(BUILD)/$(PROGRAM).elf
BIN := $(BUILD)/$(PROGRAM).bin


all: $(BIN)

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OPTIMIZE) $(INCLUDES) $(DEFINES) -c $< -o $@

$(BUILD)/%.o: %.s
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(ASFLAGS) $(DEFINES) -c $< -o $@

$(ELF): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	$(SIZE) $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $(ELF) $(BIN)


flash: $(BIN)
	@echo -e "\n\nFlashing $(MCU) | Programmer: $(PROGRAMMER) | Binary: $(BIN)"
	@$(SIZE) -A $(ELF)
ifeq ($(PROGRAMMER), minichlink)
	minichlink -i -w $< flash -b
else
	$(error Programmer not supported: $(PROGRAMMER))
endif


clean:
	$(info Cleaning build directory: $(BUILD))
ifneq ($(realpath $(BUILD)), )
	find $(BUILD)/* ! -name "*.bin" ! -name "*.elf" -delete
else
	$(error Build directory not defined)
endif


info: $(ELF)
	$(OBJDUMP) -d $<
	$(OBJDUMP) -h $<
	$(READELF) -Ws $<
	$(SIZE) -A $<
