# tiny_hal  

**Hi**!  
I've made this HAL to learn a bit more about the ch32v003 µc and to use it for future projects.  
I thought I might as well share it if other people are interested in it.  
Currently, I only have variants of the ch32v003, but I plan on getting some ch32v203 for USB support.  

I've tried to go as bare metal as possible.  
There is a C runtime init -> /boot/ch32v003_init.s which :  
 - set up the stack and global pointer
 - initialize the RAM  
 - call the \_\_init__ function internal to tiny_hal  
 - call the main function  

And a linker script -> /ld/ch32v003.ld which takes care of which sections of the program to keep and where to place them in ROM/RAM.  

The only use of the stdlib is for division, multiplications and sprintf. I didn't want to reimplement them as the footprint from newlib nano is ok (around 3kB ROM and 120B RAM for sprintf).  

Using this HAL a blink program is around 200B, but most of it is for C runtime and peripheral initialisation.  
A minimal blink which can't do much more than toggle a pin is 48B.  

## Features  

So far here's the features implemented :  
 - Register access  
 - GPIO  
 - Soft delay  
 - Logging  
 - I2C  

And the features I plan on doing (unordered) :  
 - UART  
 - Timers  
 - PWM  
 - Interrupts  
 - SPI  
 - ADC  
 - Watchdog  
 - Programmer  

This external hardware is supported :  
 - I2C 1602 LCD  

## Compilation  

In each program directory there's a Makefile with the following commands :  
 - make -> Compile the project in /build directory  
 - make flash -> Compile and flash to target  
 - make clean -> Delete all object files, keep the binaries  
 - make info -> Prints some informations about the compiled binary  

These Makefiles also contains configuration about the project, such as µc model, programmer and some definitions to pass to the preprocessor.

I've provided a script in /tools to compile your own toolchain if needed (the one from the Arch (btw) AUR doesn't support rv32ec correctly).  

## Compiler flags  

*-march=rv32ec_zicsr* -> Compile for the RISC-V 32-bit architecture with :  
 - **E**mbedded extension : 16 registers instead of 32  

 - **C**ompressed extension : some instructions are 16-bit instead of 32  
 - **Z**icsr : allows access to the **C**ontrol and **S**tatus **R**egisters  

*-mabi=ilp32e* -> Use conventions for 32bits **I**ntegers **L**ongs **P**ointers with the **E**mbedded extension  

*-ffreestanding* -> Don't assume standard functions (for example, we call void main())  

*-MMD* -> Generate dependency files to check for modifications (editing a .h will recompile the project)  

*--specs=nano.specs* -> Use newlib-nano (sprintf goes from 50kB ROM usage down to 3k)  

*-Os* -> Optimize for size instead of execution time  

*-ffunction-sections* -> Set each function in its own section  

*-fdata-sections* -> Set each variable in its own section  

*-msmall-data-limit=8* -> Data objects smaller than 8 bytes are moved to small data sections  

## Linker flags  

*-nostartfiles* -> Don't link the default C runtime init files (/boot/ch32v003_init.s is used instead)  

*-Tld/$(MCU).ld* -> Use the linker script /ld/ch32v003.ld  

*-gc-sections* -> Remove all unused sections when linking the output ELF  

*--relax* -> Enable linker relaxation to reduce code size  

*--relax-gp* -> Enable relaxation for data around the (G)lobal (P)ointer  
