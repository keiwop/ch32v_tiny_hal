# tiny_hal -> Minimal blink example  
  
| section   | size   | addr |
|:----------|:------:|:----:|
| .init     | 2      | 0    |
| .text     | 46     | 4    |
| **Total** | **48** |      |
  
Compiled size is 48 bytes.  

It costs 8 bytes to set a stack pointer, so we'll do *without* it.  

It's possible to shave **2** more bytes by removing the .init section and starting exec at .text.startup.main.  
Do it by adding **KEEP(\*(.text.startup.\*))** at the top of the .text section in the linker script.  
