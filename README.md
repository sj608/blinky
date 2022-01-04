# blinky

This repository includes board bring up process and loading of blinky file

## Hardware
Description of hardware in use. [Datasheet](Docs/Datasheet.pdf) and [Reference Manual](Doc/Reference-Manual.pdf)
### MCU
STM32F103C8T6: 

- Medium-density performance 32-bit Cortex-M3 CPU
- 72 MHz

### CMAKE

1. arm-none-eabi-gcc.cmake: information about tools to be used to build the project.
   - compiler and other tools to be used
2. 
- 64 Flash memory, 20KB of SRAM

![MCU-Naming](Docs/MCU-naming-convention.png)

## Startup file generation
following [this](https://www.youtube.com/watch?v=2Hm8eEHsgls&ab_channel=FastbitEmbeddedBrainAcademy) tutorial.

### what is startup file?
1. The startup file is responsible for setting up the right environment for the main user code to run
2. Code written in startup file runs before main()
3. some poart of the startup code file is the target dependent
4. startup code takes care of the vector table placement in code memory as required by the ARM cortex Mx processor
5. Startup code may also take care of stack re-initialization
6. startup code is responsible of .data, .bss section initialization in main memory

### vector tables
can be found in the reference manual interrupt section. The table will have brief description and address of each IQRs. The first 15 addresses are reserved for the ARM systemic sections.

When code is built without vaiable attribute for the vector table, the table is placed in data section. we would like to use compiler attribute to create a dedicated section for the table. Refer to [this](https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html#Common-Variable-Attributes) link and search for sections for more information. This image shows the vector table in data section. ![img](Docs/vector_table_in_data_section.png)

this picture is where section attribute is used for vector table section
![img](Docs/vector_table_section.png)

There are 50+ exceptions, but you don't have to write exception handlers for all the exceptions, if you are not handling all of the exceptions. A single default handler can be used for all exceptions. Allow programmer to implement required handlers as per application requirements. This can be acheived by using GCC function attributes __weak__ and __alias__ .

1. Weak allows programmer to override already defined weak function (dummy) with the same function name
   - programmer can override the function in the main file by using the same name
2. Alias allows programmer to give alias name for a function

rest of the startup code will be finished after writing the linker script


## Linker Script

1. text file which explains how different sections of the obeject files should be merged to create an output file
2. by reffering to the address information mentioned in the linker script, linker assigns the unique absolute addresses to the different sections of the output file.
3. also includes the code and data memory address and size information
4. written using GNU linker command language and file extension of .ld
5. must supplied during the linking phase to the linker using -T option

### Commands

* ENTRY
  - Entry point address inofrmation in the header of final elf file generated
  - In most cases, "Reset_Handler" is the 
  - debugger uses this information to locate the first function to execute
  - Syntax: ENTRY(Function_name)
* MEMORY
  - allows to describe the different memories present in the target and their start address and size info
  - assign addresses to merged section
  - calculate total code and data memory consumed and throw an error message if data, code heap or stack cannot fit into the available size
  - typically one linker script has one memory command
  - syntax: 

```
MEMORY
{
   name (att): ORIGIN = origin, LENGTH =len
}
```
* SECTION
  - create different output sections in the final elf
  - instruct the linker how to merge the input sections to yield an output section
  - controls the order in which different output sections appear in the elf file
  - mention the placement of a section in memory region. Example instruct the linker to place the .text section in the FLASH memory region.

```
SECTIONS
{  
    .text:
    {
       *(.isr_vector) - place vector table before the code or text section
       *(.text) - merge all text section of input files
       *(.rodata)
    }> vma(virtual memory address) AT>lma (load memory address)
    
    .data: - initialized data
    {

    }> SRAM AT> FLASH - the linker will load the data section ot FLASH then assigin absolute address to SRAM

    .bss
    {
       
    }
}
```