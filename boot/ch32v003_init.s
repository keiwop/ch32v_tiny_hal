.section .init

_sp:        /* Load stack pointer */
    la sp, __stack_top

_gp:        /* Load global pointer */
    la gp, __global_pointer

_data:      /* Copy .data section to RAM */
    la a0, __rom_data_start
    la a1, __data_start
    la a2, __data_end
    bgeu a1, a2, _bss
_data_loop:
    lw t0, (a0)
    sw t0, (a1)
    addi a0, a0, 4
    addi a1, a1, 4
    bltu a1, a2, _data_loop

_bss:       /* Initialize .bss section to 0 */
    la a0, __bss_start
    la a1, __bss_end
    bgeu a0, a1, _init
_bss_loop:
    sw zero, (a0)
    addi a0, a0, 4
    bltu a0, a1, _bss_loop

_init:      /* Init peripherals from C */
    call __init__

_main:      /* Start main loop from C*/   
    call main

_panic:     /* Panic (return from main loop): infinite loop */
    j .     /* So cute */
