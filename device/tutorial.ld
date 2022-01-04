ENTRY(reset_handler)

MEMORY
{
    FLASH(rx): ORIGIN=0x08000000, LENGTH=64K
    SRAM(rwx): ORIGIN=0x20000000, LENGTH=20K
}

SECTIONS
{  
    .text:
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
    }> FLASH AT> FLASH
    
    .data:
    {

    }> SRAM AT> FLASH

    .bss:
    {
        *(.bss)
    }> SRAM
}