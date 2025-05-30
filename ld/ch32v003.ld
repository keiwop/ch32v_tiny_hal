/* Copyright (C): 2025 - keiwop */
/* SPDX-License-Identifier: GPL-3.0-or-later */

/* If you are here, you can probably read this: */
/* https://mcyoung.xyz/2021/06/01/linker-script/ */

/* CH32V003 | 16K FLASH - 2K RAM */


ENTRY(__start)


MEMORY{
    rom (rx) : ORIGIN = 0x00000000, LENGTH = 16K
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 2K
}


SECTIONS{
    __start = .;

    .init : ALIGN(4){   /* .init comes from ch32v003.s */
        KEEP(*(.init))
    } > rom

    .text : ALIGN(4){
        *(.text)
        *(.text.*)
    } > rom

    .rodata : ALIGN(4){
        *(.rodata)
        *(.rodata*)
    } > rom

    .data : ALIGN(4){
        *(.data)
        *(.data.*)
    } > ram AT> rom

    .sdata : ALIGN(8){
        __global_pointer = . + 0x800;   /* GP can access a 12-bit address space so place it halfway there */
        *(.sdata)
        *(.sdata.*)
    } > ram AT> rom

    .srodata (READONLY) : ALIGN(8){     /* Store small const vars in RAM (trades ROM for RAM and makes use of small data optimization) */
        *(.srodata.cst16)
        *(.srodata.cst8)
        *(.srodata.cst4)
        *(.srodata.cst2)
        *(.srodata)
        *(.srodata.*)
    } > ram AT> rom

    .sbss : ALIGN(8){
        *(.sbss*)
    } > ram

    .bss : ALIGN(4){
        *(.bss)
        *(.bss.*)
    } > ram

    /DISCARD/ : {
        *(.comment)
        *(.riscv.attributes)
    }
}

__rom_data_start = LOADADDR(.data);

__data_start = ADDR(.data);
__data_end = __data_start + SIZEOF(.data) + SIZEOF(.sdata) + SIZEOF(.srodata);

__bss_start = ADDR(.sbss);
__bss_end = __bss_start + SIZEOF(.sbss) + SIZEOF(.bss);

__stack_top = ORIGIN(ram) + LENGTH(ram);
