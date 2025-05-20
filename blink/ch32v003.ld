/* CH32V003 | 16K FLASH - 2K RAM */

MEMORY{
    rom (rx) : ORIGIN = 0x00000000, LENGTH = 16K
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 2K
}


SECTIONS{
    .init : ALIGN(4){   /* .init comes from ch32v003.s */
        *(.init)
    } > rom

    .text : ALIGN(4){
        *(.text)
        *(.text.*)
    } > rom

    .rodata : ALIGN(4){
        *(.rodata)
        *(.rodata.*)
    } > rom

    .data : ALIGN(4){
        *(.data)
        *(.data.*)
        . = ALIGN(8);
        __global_pointer = . + 0x800;   /* GP can access a 12-bit address space so place it halfway there */
        *(.sdata)
        *(.sdata.*)
        . = ALIGN(8);                   /* Store small const vars in RAM (trades ROM for RAM and makes use of small data optimization) */
        *(.srodata.cst16)
        *(.srodata.cst8)
        *(.srodata.cst4)
        *(.srodata.cst2)
        *(.srodata)
        *(.srodata.*)
    } > ram AT> rom

    .bss : ALIGN(8){
        *(.sbss*)
        . = ALIGN(4);
        *(.bss)
        *(.bss.*)
    } > ram
}

__rom_data_start = LOADADDR(.data);

__data_start = ADDR(.data);
__data_end = __data_start + SIZEOF(.data);

__bss_start = ADDR(.bss);
__bss_end = __bss_start + SIZEOF(.bss);

__stack_top = ORIGIN(ram) + LENGTH(ram);
