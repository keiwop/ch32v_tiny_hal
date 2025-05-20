
# Compilation  
riscv64-elf-gcc -nostartfiles -march=rv32ec -mabi=ilp32e -Os -T ch32v003.ld ch32v003_init.s debug.c init.c blink.c  
riscv64-elf-objcopy -Obinary a.out blink.bin  

# Flash
minichlink -i -w blink.bin flash -b  

