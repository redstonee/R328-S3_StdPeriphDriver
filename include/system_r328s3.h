#pragma once

#include <basic.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define HOSC_FREQ 24000000UL

extern uint32_t SystemCoreClock;
void UpdateSystemCoreClock(uint32_t freq);

uint32_t micros(void);
uint32_t millis(void);

void delay(uint32_t ms);
void delayMicroseconds(uint32_t us);

#ifdef __cplusplus
}
#endif // __cplusplus
