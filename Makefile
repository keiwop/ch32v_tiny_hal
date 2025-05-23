
PROGRAM     ?= undefined
MCU         ?= ch32v003
PROGRAMMER  ?= minichlink

# Toolchain
TOOLCHAIN   := riscv64-elf-
CC 			:= $(TOOLCHAIN)gcc
AS          := $(TOOLCHAIN)as
LD          := $(TOOLCHAIN)ld
OBJCOPY     := $(TOOLCHAIN)objcopy
OBJDUMP     := $(TOOLCHAIN)objdump
SIZE        := $(TOOLCHAIN)size

# Flags
CFLAGS      := -march=rv32ec -mabi=ilp32e -Wall -ffreestanding -MMD
OPTIMIZE    := -Os -ffunction-sections -fdata-sections -msmall-data-limit=8
ASFLAGS     := -x assembler-with-cpp
LDFLAGS     := -nostartfiles -Tld/$(MCU).ld -Wl,-gc-sections,--print-gc-sections -Wl,--relax -Wl,--relax-gp

INCLUDES    ?= -Itiny_hal/include
DEFINES 	?= 

BUILD       ?= build


ASM := $(PROG_ASM) \
    boot/$(MCU)_init.s

SRC += $(PROG_SRC) \
    tiny_hal/src/debug.c \
    tiny_hal/src/init.c


C_OBJ := $(patsubst %.c,$(BUILD)/%.o,$(SRC))
S_OBJ := $(patsubst %.s,$(BUILD)/%.o,$(ASM))
OBJ := $(C_OBJ) $(S_OBJ)
$(info ASM = $(ASM))
$(info SRC = $(SRC))
$(info OBJ = $(OBJ))

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


flash: $(ELF)
	@echo -e "\n\nFlashing $(MCU) | Programmer: $(PROGRAMMER) | Binary: $(BIN)"
	@$(SIZE) -A $<
ifeq ($(PROGRAMMER), minichlink)
	minichlink -i -b -w $< flash
else
	$(error Programmer not supported: $(PROGRAMMER))
endif


# https://github.com/naegelyd/til/blob/master/misc/check-if-directory-exists-in-makefile.md
clean:
	$(info Cleaning build directory: $(BUILD))
ifneq ("$(wildcard $(BUILD))", "")
	find $(BUILD)/* ! -name "*.bin" ! -name "*.elf" -delete
else
	$(error Build directory not defined)
endif
