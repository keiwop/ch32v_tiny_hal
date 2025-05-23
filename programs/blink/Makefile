
PROGRAM     := blink
MCU         := ch32v003
PROGRAMMER  := minichlink
BOOT        := init


ASM         :=
SRC         := blink.c

DEFINES     := -DF_CPU=24000000UL


PROG_PATH   := $(realpath .)
.DEFAULT_GOAL := all

%:
	$(MAKE) -C ../.. $@ \
        PROGRAM="$(PROGRAM)" MCU="$(MCU)" BOOT="$(BOOT)" PROGRAMMER="$(PROGRAMMER)" \
        PROG_PATH="$(PROG_PATH)" PROG_ASM="$(ASM)" PROG_SRC="$(SRC)" DEFINES="$(DEFINES)"
