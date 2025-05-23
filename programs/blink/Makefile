
PROGRAM     := blink
MCU         := ch32v003
PROGRAMMER  := minichlink

ASM         :=
SRC         := programs/$(PROGRAM)/blink.c

DEFINES     := -DF_CPU=24000000UL


all:
	$(MAKE) -C ../.. $@ PROGRAM="$(PROGRAM)" MCU="$(MCU)" PROG_ASM="$(ASM)" PROG_SRC="$(SRC)" DEFINES="$(DEFINES)"

%:
	$(MAKE) -C ../.. $@ PROGRAM="$(PROGRAM)" MCU="$(MCU)" PROG_ASM="$(ASM)" PROG_SRC="$(SRC)" DEFINES="$(DEFINES)"
