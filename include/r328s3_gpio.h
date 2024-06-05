#pragma once

#include "R328S3.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

    typedef struct
    {
        __IO uint32_t CFG0;  // 0x00 : Configuration Register 0
        __IO uint32_t CFG1;  // 0x04 : Configuration Register 1
        __IO uint32_t CFG2;  // 0x08 : Configuration Register 2
        __IO uint32_t CFG3;  // 0x0C : Configuration Register 3, useless
        __IO uint32_t DAT;   // 0x10 : Data Register
        __IO uint32_t DRV0;  // 0x14 : Multi-Driving Register 0
        __IO uint32_t DRV1;  // 0x18 : Multi-Driving Register 1
        __IO uint32_t PULL0; // 0x1C : Pull-up/down Register 0
        __IO uint32_t PULL1; // 0x20 : Pull-up/down Register 1

    } GPIO_TypeDef;

    typedef struct
    {
        __IO uint32_t CFG0; // 0x00 : Interrupt Configuration Register 0
        __IO uint32_t CFG1; // 0x04 : Interrupt Configuration Register 1
        __IO uint32_t CFG2; // 0x08 : Interrupt Configuration Register 2
        __IO uint32_t CFG3; // 0x0C : Interrupt Configuration Register 3
        __IO uint32_t CTL;  // 0x10 : Interrupt Control Register
        __IO uint32_t STA;  // 0x14 : Interrupt Status Register
        __IO uint32_t DEB;  // 0x18 : Interrupt De-bounce Register
    } EINT_TypeDef;

#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOG ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *)GPIOH_BASE)

#define PB_EINT ((EINT_TypeDef *)PB_EINT_BASE)
#define PE_EINT ((EINT_TypeDef *)PE_EINT_BASE)
#define PG_EINT ((EINT_TypeDef *)PG_EINT_BASE)
#define PH_EINT ((EINT_TypeDef *)PH_EINT_BASE)

    typedef enum
    {
        GPIO_Mode_IN = 0,  /*!< GPIO input */
        GPIO_Mode_OUT,     /*!< GPIO output */
        GPIO_Mode_AF1,     /*!< GPIO alternate function 1 */
        GPIO_Mode_AF2,     /*!< GPIO alternate function 2 */
        GPIO_Mode_AF3,     /*!< GPIO alternate function 3 */
        GPIO_Mode_AF4,     /*!< GPIO alternate function 4 */
        GPIO_Mode_EINT,    /*!< GPIO external interrupt */
        GPIO_Mode_DISABLE, /*!< GPIO disable */
    } GPIOMode_TypeDef;

    typedef enum
    {
        GPIO_Strength_L0 = 0, /*!< 180 Ohm */
        GPIO_Strength_L1 = 1, /*!< 90 Ohm */
        GPIO_Strength_L2 = 2, /*!< 45 Ohm */
        GPIO_Strength_L3 = 3, /*!< 22 Ohm */
    } GPIOStrength_TypeDef;

    typedef enum
    {
        GPIO_NoPull = 0, /*!< GPIO no pull-up */
        GPIO_PullUp,     /*!< GPIO pull-up */
        GPIO_PullDown,   /*!< GPIO pull-down */
    } GPIOPull_TypeDef;

    typedef enum
    {
        Bit_RESET = 0,
        Bit_SET
    } BitAction;

    typedef struct
    {
        uint32_t Pin;                  /*!< GPIO pin */
        GPIOMode_TypeDef Mode;         /*!< GPIO mode */
        GPIOStrength_TypeDef Strength; /*!< GPIO buffer strength */
        GPIOPull_TypeDef GPIO_Pull;    /*!< GPIO pull */
    } GPIO_InitTypeDef;

    typedef enum
    {
        EINT_Mode_Rising = 0, // Positive edge
        EINT_Mode_Falling,    // Negative edge
        EINT_Mode_High,       // High level
        EINT_Mode_Low,        // Low level
        EINT_Mode_Change,     // Both edge
    } EINT_TriggerMode;

    typedef enum
    {
        LOSC = 0, // 32KHz
        HOSC = 1, // 24MHz
    } EINT_FilterClock;

#define GPIO_Pin_None ((uint32_t)0)
#define GPIO_Pin_0 ((uint32_t)0x0001)
#define GPIO_Pin_1 ((uint32_t)0x0002)
#define GPIO_Pin_2 ((uint32_t)0x0004)
#define GPIO_Pin_3 ((uint32_t)0x0008)
#define GPIO_Pin_4 ((uint32_t)0x0010)
#define GPIO_Pin_5 ((uint32_t)0x0020)
#define GPIO_Pin_6 ((uint32_t)0x0040)
#define GPIO_Pin_7 ((uint32_t)0x0080)
#define GPIO_Pin_8 ((uint32_t)0x0100)
#define GPIO_Pin_9 ((uint32_t)0x0200)
#define GPIO_Pin_10 ((uint32_t)0x0400)
#define GPIO_Pin_11 ((uint32_t)0x0800)
#define GPIO_Pin_12 ((uint32_t)0x1000)
#define GPIO_Pin_13 ((uint32_t)0x2000)
#define GPIO_Pin_14 ((uint32_t)0x4000)
#define GPIO_Pin_15 ((uint32_t)0x8000)
#define GPIO_Pin_16 ((uint32_t)0x10000)

    void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);
    void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct);

#define GPIO_Write(GPIOx, Val) ((GPIOx)->DAT = (Val))
#define GPIO_Read(GPIOx) ((GPIOx)->DAT)

#define GPIO_WriteBits(GPIOx, GPIO_Pin, BitVal) ((BitVal) ? ((GPIOx)->DAT |= (GPIO_Pin)) : ((GPIOx)->DAT &= ~(GPIO_Pin)))
#define GPIO_ReadBit(GPIOx, GPIO_Pin) ((GPIOx)->DAT & (GPIO_Pin) ? Bit_SET : Bit_RESET)
#define GPIO_ToggleBits(GPIOx, GPIO_Pin) ((GPIOx)->DAT ^= (GPIO_Pin))

    /*
     * @brief Configure the trigger mode for the external interrupt
     * @param PnEINT: The external interrupt peripheral
     * @param nEINT: The external interrupt number
     * @param mode: The trigger mode
     */
    void EINT_SetTriggerMode(EINT_TypeDef *PnEINT, uint8_t GPIO_Pin, EINT_TriggerMode mode);

/*
 * @brief Configure the filter for the external interrupt
 * @param PnEINT: The external interrupt peripheral
 * @param clock: The clock source for the filter
 * @param prescale: The prescale value (n) for the filter, the filter width is 2^n
 */
#define EINT_SetDebounce(PnEINT, clock, prescale) (PnEINT->DEB = ((clock) | ((prescale & 7) << 4)))

#define EINT_Enable(PnEINT, GPIO_Pin) (PnEINT->CTL &= GPIO_Pin)
#define EINT_Disable(PnEINT, GPIO_Pin) (PnEINT->CTL |= GPIO_Pin)
#define EINT_GetPending(PnEINT, GPIO_Pin) ((PnEINT->STA & GPIO_Pin) ? 1 : 0)
#define EINT_ClearPending(PnEINT, GPIO_Pin) (PnEINT->STA |= GPIO_Pin)

#ifdef __cplusplus
}
#endif
