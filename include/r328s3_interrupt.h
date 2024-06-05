#pragma once

#include "R328S3.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        uint32_t RESERVED0[1024];
        __IO uint32_t D_CTLR; /*!< Offset: 0x1000 (R/W) Distributor Control Register */
        __I uint32_t D_TYPER; /*!< Offset: 0x1004 (R/ )  Interrupt Controller Type Register */
        __I uint32_t D_IIDR;  /*!< Offset: 0x1008 (R/ )  Distributor Implementer Identification Register */
        uint32_t RESERVED1[29];
        __IO uint32_t D_IGROUPR[16]; /*!< Offset: 0x1080 - 0x0BC (R/W) Interrupt Group Registers */
        uint32_t RESERVED2[16];
        __IO uint32_t D_ISENABLER[16]; /*!< Offset: 0x1100 - 0x13C (R/W) Interrupt Set-Enable Registers */
        uint32_t RESERVED3[16];
        __IO uint32_t D_ICENABLER[16]; /*!< Offset: 0x1180 - 0x1BC (R/W) Interrupt Clear-Enable Registers */
        uint32_t RESERVED4[16];
        __IO uint32_t D_ISPENDR[16]; /*!< Offset: 0x1200 - 0x23C (R/W) Interrupt Set-Pending Registers */
        uint32_t RESERVED5[16];
        __IO uint32_t D_ICPENDR[16]; /*!< Offset: 0x1280 - 0x2BC (R/W) Interrupt Clear-Pending Registers */
        uint32_t RESERVED6[16];
        __IO uint32_t D_ISACTIVER[16]; /*!< Offset: 0x1300 - 0x33C (R/W) Interrupt Set-Active Registers */
        uint32_t RESERVED7[16];
        __IO uint32_t D_ICACTIVER[16]; /*!< Offset: 0x1380 - 0x3BC (R/W) Interrupt Clear-Active Registers */
        uint32_t RESERVED8[16];
        __IO uint8_t D_IPRIORITYR[512]; /*!< Offset: 0x1400 - 0x5FC (R/W) Interrupt Priority Registers */
        uint32_t RESERVED9[128];
        __IO uint8_t D_ITARGETSR[512]; /*!< Offset: 0x1800 - 0x9FC (R/W) Interrupt Targets Registers */
        uint32_t RESERVED10[128];
        __IO uint32_t D_ICFGR[32]; /*!< Offset: 0x1C00 - 0xC7C (R/W) Interrupt configuration registers */
        uint32_t RESERVED11[32];
        __I uint32_t D_PPISR;     /*!< Offset: 0x1D00 (R/ ) Private Peripheral Interrupt Status Register */
        __I uint32_t D_SPISR[15]; /*!< Offset: 0x1D04 - 0xD3C (R/ ) Shared Peripheral Interrupt Status Registers */
        uint32_t RESERVED12[112];
        __O uint32_t D_SGIR; /*!< Offset: 0x1F00 ( /W) Software Generated Interrupt Register */
        uint32_t RESERVED13[3];
        __IO uint8_t D_CPENDSGIR[16]; /*!< Offset: 0x1F10 - 0xF1C (R/W) SGI Clear-Pending Registers */
        __IO uint8_t D_SPENDSGIR[16]; /*!< Offset: 0x1F20 - 0xF2C (R/W) SGI Set-Pending Registers */
        uint32_t RESERVED14[40];
        __I uint32_t D_PIDR4; /*!< Offset: 0x1FD0 (R/ ) Peripheral ID4 Register */
        __I uint32_t D_PIDR5; /*!< Offset: 0x1FD4 (R/ ) Peripheral ID5 Register */
        __I uint32_t D_PIDR6; /*!< Offset: 0x1FD8 (R/ ) Peripheral ID6 Register */
        __I uint32_t D_PIDR7; /*!< Offset: 0x1FDC (R/ ) Peripheral ID7 Register */
        __I uint32_t D_PIDR0; /*!< Offset: 0x1FE0 (R/ ) Peripheral ID0 Register */
        __I uint32_t D_PIDR1; /*!< Offset: 0x1FE4 (R/ ) Peripheral ID1 Register */
        __I uint32_t D_PIDR2; /*!< Offset: 0x1FE8 (R/ ) Peripheral ID2 Register */
        __I uint32_t D_PIDR3; /*!< Offset: 0x1FEC (R/ ) Peripheral ID3 Register */
        __I uint32_t D_CIDR0; /*!< Offset: 0x1FF0 (R/ ) Component ID0 Register */
        __I uint32_t D_CIDR1; /*!< Offset: 0x1FF4 (R/ ) Component ID1 Register */
        __I uint32_t D_CIDR2; /*!< Offset: 0x1FF8 (R/ ) Component ID2 Register */
        __I uint32_t D_CIDR3; /*!< Offset: 0x1FFC (R/ ) Component ID3 Register */

        __IO uint32_t C_CTLR;  /*!< Offset: 0x2000 (R/W) CPU Interface Control Register */
        __IO uint32_t C_PMR;   /*!< Offset: 0x2004 (R/W) Interrupt Priority Mask Register */
        __IO uint32_t C_BPR;   /*!< Offset: 0x2008 (R/W) Binary Point Register */
        __I uint32_t C_IAR;    /*!< Offset: 0x200C (R/ ) Interrupt Acknowledge Register */
        __O uint32_t C_EOIR;   /*!< Offset: 0x2010 ( /W) End Of Interrupt Register */
        __I uint32_t C_RPR;    /*!< Offset: 0x2014 (R/ ) Running Priority Register */
        __I uint32_t C_HPPIR;  /*!< Offset: 0x2018 (R/ ) Highest Priority Pending Interrupt Register */
        __IO uint32_t C_ABPR;  /*!< Offset: 0x201C (R/W) Aliased Binary Point Register */
        __I uint32_t C_AIAR;   /*!< Offset: 0x2020 (R/ ) Aliased Interrupt Acknowledge Register */
        __O uint32_t C_AEOIR;  /*!< Offset: 0x2024 ( /W) Aliased End Of Interrupt Register */
        __I uint32_t C_AHPPIR; /*!< Offset: 0x2028 (R/ ) Aliased Highest Priority Pending Interrupt Register */
        uint32_t RESERVED15[41];
        __IO uint32_t C_APR0; /*!< Offset: 0x20D0 (R/W) Active Priority Register */
        uint32_t RESERVED16[3];
        __IO uint32_t C_NSAPR0; /*!< Offset: 0x20E0 (R/W) Non-secure Active Priority Register */
        uint32_t RESERVED17[6];
        __I uint32_t C_IIDR; /*!< Offset: 0x20FC (R/ ) CPU Interface Identification Register */
        uint32_t RESERVED18[960];
        __O uint32_t C_DIR; /*!< Offset: 0x3000 ( /W) Deactivate Interrupt Register */
    } GIC_Type;

#define GIC ((GIC_Type *)INT_BASE)

    typedef enum
    {
        SRC_EINT0 = 1 << 0,
        SRC_EINT1 = 1 << 1,
        SRC_EINT2 = 1 << 2,
        SRC_EINT3 = 1 << 3,
        SRC_EINT4_7 = 1 << 4,
        SRC_EINT8_13 = 1 << 5,

        SRC_BATT_FTL = 1 << 7,
        SRC_INT_TICK = 1 << 8,
        SRC_INT_WDT = 1 << 9,
        SRC_INT_TIM0 = 1 << 10,
        SRC_INT_TIM1 = 1 << 11,
        SRC_INT_TIM2 = 1 << 12,
        SRC_INT_TIM3 = 1 << 13,
        SRC_INT_TIM4 = 1 << 14,
        SRC_INT_UART2 = 1 << 15,
        SRC_INT_LCD = 1 << 16,
        SRC_INT_DMA0 = 1 << 17,
        SRC_INT_DMA1 = 1 << 18,
        SRC_INT_DMA2 = 1 << 19,
        SRC_INT_DMA3 = 1 << 20,
        SRC_INT_SDI = 1 << 21,
        SRC_INT_SPI9 = 1 << 22,
        SRC_INT_UART1 = 1 << 23,

        SRC_INT_USBD = 1 << 25,
        SRC_INT_USBH = 1 << 26,
        SRC_INT_I2C = 1 << 27,
        SRC_INT_UART0 = 1 << 28,
        SRC_INT_SPI1 = 1 << 29,
        SRC_INT_RTC = 1 << 30,
        SRC_INT_ADC = 1 << 31,
    } InterruptSource;

    typedef enum
    {
        SUBSRC_INT_RXD0 = 1,
        SUBSRC_INT_TXD0 = 1 << 1,
        SUBSRC_INT_ERR0 = 1 << 2,
        SUBSRC_INT_RXD1 = 1 << 3,
        SUBSRC_INT_TXD1 = 1 << 4,
        SUBSRC_INT_ERR1 = 1 << 5,
        SUBSRC_INT_RXD2 = 1 << 6,
        SUBSRC_INT_TXD2 = 1 << 7,
        SUBSRC_INT_ERR2 = 1 << 8,
        SUBSRC_INT_TC = 1 << 9,
        SUBSRC_INT_ADC = 1 << 10,
    } SubInterruptource;

    typedef enum
    {
        MODE_IRQ = 0,
        MODE_FIQ = 1
    } InterruptMode;

// Set whether IRQ(0) or FIQ(1), default is IRQ
#define INT_SetMode(src, mode) (mode ? (Interrupt->INTMOD |= src) : (Interrupt->INTMOD &= (~src)))

#define INT_Enable(src) (Interrupt->INTMSK &= (~src))
#define INT_Disable(src) (Interrupt->INTMSK |= src)

#define INT_EnableSub(subsrc) (Interrupt->SUBINTMSK &= (~subsrc))
#define INT_DisableSub(subsrc) (Interrupt->SUBINTMSK |= subsrc)

#define INT_GetSourcePending(src) (Interrupt->SRCPND & src != 0)
#define INT_GetInterruptPending(src) ((Interrupt->INTPND & src) != 0)

// Write 1 to clear, which is fucking weired
#define INT_ClearInterruptPending() (Interrupt->INTPND = Interrupt->INTPND) // Only 1 bit will be set at a time
#define INT_ClearSourcePending(src) (Interrupt->SRCPND |= src)

#define INT_GetSubSourcePending(subsrc) ((Interrupt->SUBSRCPND & subsrc == 0) ? 0 : 1)
#define INT_ClearSubSourcePending(subsrc) (Interrupt->SUBSRCPND |= subsrc)

#ifdef __cplusplus
}
#endif