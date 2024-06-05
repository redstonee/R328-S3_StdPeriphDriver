#include "system_r328s3.h"
#include "r328s3_dcxo.h"

uint32_t SystemCoreClock;

void UpdateSystemCoreClock(uint32_t freq){
    SystemCoreClock = freq;
}


void system_init(void)
{
    UpdateSystemCoreClock(HOSC_FREQ);
    /* Configure general timer */
    asm volatile("mcr p15, 0, %0, c14, c0, 0"
                 :
                 : "r"(SystemCoreClock)
                 :);

    /* Configure LDO Voltage */
    DCXO->LDO_CTRL = 0x80; // LDOB 1.5V for DDR3, LDOA 1.8V for AVCC&PLL
}

/*
 * 64bit arch timer.CNTPCT
 * Freq = 24000000Hz
 */
uint64_t get_arch_counter(void)
{
    uint32_t low = 0, high = 0;
    asm volatile("mrrc p15, 0, %0, %1, c14"
                 : "=r"(low), "=r"(high)
                 :
                 : "memory");
    return ((uint64_t)high << 32) | (uint64_t)low;
}

uint32_t millis(void)
{
    return get_arch_counter() / 24000;
}

uint32_t micros(void)
{
    return get_arch_counter() / 24;
}

void delay(uint32_t ms)
{
    uint64_t start = get_arch_counter();
    while (get_arch_counter() - start < ms * 24000)
        ;
}

void delayMicroseconds(uint32_t us)
{
    uint64_t start = get_arch_counter();
    while (get_arch_counter() - start < us * 24)
        ;
}