
# Compiler flags  
# -march=rv32ec_zicsr   -> Compile for the RISC-V 32-bit architecture with :
#   (E)mbedded extension : 16 registers instead of 32
#   (C)ompressed extension : some instructions are 16-bit instead of 32
#   (Z)icsr : allows access to the (C)ontrol and (S)tatus (R)egisters
# -mabi=ilp32e          -> Use conventions for 32bits (I)ntegers (L)ongs (P)ointers with the (E)mbedded extension
# -ffreestanding        -> Don't assume standard functions (for example, we call void main())
# -MMD                  -> Generate dependency files to check for modifications (editing a .h will recompile the project)
# --specs=nano.specs    -> Use newlib-nano (sprintfs goes from 50k ROM usage down to 3k)
# -Os                   -> Optimize for size instead of execution time
# -ffunction-sections   -> Set each function in its own section
# -fdata-sections       -> Set each variable in its own section
# -msmall-data-limit=8  -> Data objects smaller than 8 bytes are moved to small data sections

# Linker flags  
# -nostartfiles         -> Don't link the default C runtime init files (/boot/ch32v003.s is used instead)
# -Tld/$(MCU).ld        -> Use the linker script /ld/ch32v003.ld
# -Wl,-gc-sections      -> Remove all unused sections when linking the output ELF
# -Wl,--relax           -> Enable linker relaxation to reduce code size
# -Wl,--relax-gp        -> Enable relaxation for data around the (G)lobal (P)ointer
