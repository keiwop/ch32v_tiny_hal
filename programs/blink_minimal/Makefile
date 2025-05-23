
PROGRAM     := blink_minimal
MCU         := ch32v003
PROGRAMMER  := minichlink
BOOT        := minimal

ASM         :=
SRC         := programs/$(PROGRAM)/blink_minimal.c

DEFINES     := -DF_CPU=24000000UL


all:
	$(MAKE) -C ../.. $@ PROGRAM="$(PROGRAM)" MCU="$(MCU)" PROGRAMMER="$(PROGRAMMER)" BOOT="$(BOOT)" PROG_ASM="$(ASM)" PROG_SRC="$(SRC)" DEFINES="$(DEFINES)"

%:
	$(MAKE) -C ../.. $@ PROGRAM="$(PROGRAM)" MCU="$(MCU)" PROGRAMMER="$(PROGRAMMER)" BOOT="$(BOOT)" PROG_ASM="$(ASM)" PROG_SRC="$(SRC)" DEFINES="$(DEFINES)"
