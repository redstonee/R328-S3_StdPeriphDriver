#pragma once

#include <R328S3.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        __IO uint32_t IRQ_EN;  // 0x00 Timer interrupt enable
        __IO uint32_t IRQ_STA; // 0x04 Timer interrupt status
    } TIM_IRQ_TypeDef;

    typedef struct
    {
        __IO uint32_t CTRL; // 0x00 Timer control
        __IO uint32_t INTV; // 0x04 Timer interval
        __IO uint32_t CURV; // 0x08 Timer current value
    } TIM_0_3_TypeDef;

#define TIM_IRQ ((TIM_IRQ_TypeDef *)TIM_IRQ_BASE)
#define TIM0 ((TIM_0_3_TypeDef *)TIM0_BASE)
#define TIM1 ((TIM_0_3_TypeDef *)TIM1_BASE)

    typedef enum
    {
        TIM_Mode_Continous = 0,
        TIM_Mode_Single
    } TIM_Mode;

    typedef enum
    {
        TIM_Prescaler_1 = 0,
        TIM_Prescaler_2,
        TIM_Prescaler_4,
        TIM_Prescaler_8,
        TIM_Prescaler_16,
        TIM_Prescaler_32,
        TIM_Prescaler_64,
        TIM_Prescaler_128
    } TIM_Prescaler;

    typedef enum
    {
        TIM_CLK_SRC_LOSC = 0, // 32KHz
        TIM_CLK_SRC_HOSC      // 24MHz
    } TIM_CLK_SRC;

#define TIM0_IRQ_Enable(enable) ((enable ? (TIM_IRQ->IRQ_EN |= 1) : (TIM_IRQ->IRQ_EN &= ~1)))
#define TIM1_IRQ_Enable(enable) ((enable ? (TIM_IRQ->IRQ_EN |= 2) : (TIM_IRQ->IRQ_EN &= ~2)))

#define TIM0_Get_IRQ_Status() (TIM_IRQ->IRQ_STA & 1)
#define TIM1_Get_IRQ_Status() (TIM_IRQ->IRQ_STA & 2 ? 1 : 0)

#define TIM0_Clear_IRQ() (TIM_IRQ->IRQ_STA |= 1)
#define TIM1_Clear_IRQ() (TIM_IRQ->IRQ_STA |= 2)

/*
 * @brief Set the mode for a timer
 * @param TIMx: Timer to set the mode for
 * @param mode: Mode to set
 */
#define TIM_Set_Mode(TIMx, mode) (mode ? (TIMx->CTRL |= 1 << 7) : (TIMx->CTRL &= ~(1 << 7)))

/*
 * @brief Set the prescaler for a timer
 * @param TIMx: Timer to set the prescaler for
 * @param prescaler: Prescaler to set
 */
#define TIM_Set_Prescaler(TIMx, prescaler) (TIMx->CTRL = (TIMx->CTRL & ~(0x7 << 4)) | (prescaler << 4))

/*
 * @brief Set the clock source for a timer
 * @param TIMx: Timer to set the clock source for
 * @param src: Clock source to set
 */
#define TIM_Set_Clock_Source(TIMx, src) (src ? (TIMx->CTRL |= 1 << 2) : (TIMx->CTRL &= ~(1 << 2)))

#define TIM_Enable(TIMx) (TIMx->CTRL |= 1)
#define TIM_Disable(TIMx) (TIMx->CTRL &= ~1)

#define TIM_Set_Interval(TIMx, interval) (TIMx->INTV = interval)
#define TIM_Get_Current_Value(TIMx) (TIMx->CURV)

#define TIM_Reload(TIMx)    \
    (TIMx->CTRL |= 1 << 1); \
    while (TIMx->CTRL & (1 << 1))

#ifdef __cplusplus
}
#endif