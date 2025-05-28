
PROGRAM     := i2c_1602_lcd
MCU         := ch32v003
PROGRAMMER  := minichlink
BOOT        := init


ASM         :=
SRC         := i2c_1602_lcd.c

DEFINES     := -DF_CPU=24000000UL -DENABLE_I2C -DENABLE_1602_I2C -DI2C_ADDR_1602=0b0100111


PROG_PATH   := $(realpath .)
.DEFAULT_GOAL := all

%:
	$(MAKE) -C ../.. $@ \
        PROGRAM="$(PROGRAM)" MCU="$(MCU)" BOOT="$(BOOT)" PROGRAMMER="$(PROGRAMMER)" \
        PROG_PATH="$(PROG_PATH)" PROG_ASM="$(ASM)" PROG_SRC="$(SRC)" DEFINES="$(DEFINES)"
