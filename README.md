# blinky

This repository includes board bring up process and loading of blinky file

## Hardware
Description of hardware in use. [Datasheet](Docs/Datasheet.pdf) and [Reference Manual](Doc/Reference-Manual.pdf)
### MCU
STM32F103C8T6: 

- Medium-density performance 32-bit Cortex-M3 CPU
- 72 MHz
- 64 ir 128KB Flash memory, 20KB of SRAM

### CMAKE

1. arm-none-eabi-gcc.cmake: information about tools to be used to build the project.
   - compiler and other tools to be used
2. 