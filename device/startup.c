#include <stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE (20U * 1024U) //20KB
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

void reset_handler(void);

uint32_t vectors[] = {
    STACK_START,
    (uint32_t) &reset_handler,
};

void reset_handler(void)
{

}