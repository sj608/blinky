#include <stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE (20U * 1024U) //20KB
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

void reset_Handler(void);
void NMI_Handler(void)          __attribute__((weak, alias("Default_handler")));
void HardFault_Handler(void)    __attribute__((weak, alias("Default_handler")));
void MemManage_Handler(void)    __attribute__((weak, alias("Default_handler")));
void BusFault_Handler(void)    __attribute__((weak, alias("Default_handler")));
void UsageFault_Handler(void)    __attribute__((weak, alias("Default_handler")));
void SVCCall_Handler(void)    __attribute__((weak, alias("Default_handler")));
void DebugMonitor_Handler(void)    __attribute__((weak, alias("Default_handler")));
void PendSV_Handler(void)    __attribute__((weak, alias("Default_handler")));
void SysTick_Handler(void)    __attribute__((weak, alias("Default_handler")));

// 
uint32_t vectors[] = {
    STACK_START,
    (uint32_t)&reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)&SVCCall_Handler,
    (uint32_t)&DebugMonitor_Handler,
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler
}; __attribute__((section (".isr_vector")))

void Default_handler(void)
{
    while(1);
}

void reset_handler(void)
{

}