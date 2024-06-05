#include "R328S3.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        __IO uint32_t LOSC_CTRL;           /*!< 0x00 LOSC Control Register */
        __IO uint32_t LOSC_AUTO_SWT;       /*!< 0x04 LOSC Auto Switch Status Register */
        __IO uint32_t INTOSC_CLK_PRESCAL;  /*!< 0x08 Internal OSC Clock Prescaler Register */
        uint32_t RESERVED0[0x15];          /*!< 0x0C - 0x5C Reserved */
        __IO uint32_t LOSC_OUT_GATING;     /*!< 0x60 LOSC Output Gating Register */
        uint32_t RESERVED1[0x03];          /*!< 0x64 - 0x6C Reserved */
        __IO uint32_t RTC_VER;             /*!< 0x70 RTC Version Register */
        uint32_t RESERVED2[0x23];          /*!< 0x74 - 0xFC Reserved */
        __IO uint32_t GP_DATA[8];          /*!< 0x100 - 0x11C General Purpose Data Register */
        uint32_t RESERVED3[0x10];          /*!< 0x120 - 0x15C Reserved */
        __IO uint32_t XO_CTRL;             /*!< 0x160 XO Control Register */
        uint32_t RESERVED4[0x23];          /*!< 0x164 - 0x1EC Reserved */
        __IO uint32_t IC_CHARA;            /*!< 0x1F0 IC Characteristics Register */
        uint32_t RESERVED5[0x7];           /*!< 0x1F4 - 0x20C Reserved */
        __IO uint32_t CRY_CONFIG;          /*!< 0x210 Crypt Configuration Register */
        __IO uint32_t CRY_KEY;             /*!< 0x214 Crypt Key Register */
        __IO uint32_t CRY_EN;              /*!< 0x218 Crypt Enable Register */
        uint32_t RESERVED6;                /*!< 0x21C Reserved */
        __IO uint32_t VDD_SYS_PWROFF_GATE; /*!< 0x220 VDD_SYS Power Off Gating Register */
        __IO uint32_t PLL_CTRL0;           /*!< 0x224 PLL Control Register 0 */
        __IO uint32_t PLL_CTRL1;           /*!< 0x228 PLL Control Register 1 */
        uint32_t RESERVED7;                /*!< 0x22C Reserved */
        __IO uint32_t RES_CAL_CTRL;        /*!< 0x230 Resistor Calibration Control Register */
        __IO uint32_t RES200_CTRL;         /*!< 0x234 200 Ohm Resistor Control Register */
        __IO uint32_t RES240_CTRL;         /*!< 0x238 240 Ohm Resistor Control Register */
        __IO uint32_t RES_CAL_STATUS;      /*!< 0x23C Resistor Calibration Status Register */
        __IO uint32_t NMI_CTRL;            /*!< 0x240 NMI Control Register */
        uint32_t RESERVED8[0x4];           /*!< 0x244 - 0x250 Reserved */
        __IO uint32_t LDO_CTRL;            /*!< 0x254 LDO Control Register */
        __IO uint32_t CPU1_SOFT_ENT;       /*!< 0x258 CPU1 Software Entry Register */
        uint32_t RESERVED9;                // 0x25c Reserved
        __IO uint32_t EMP0;            // 0x0260 Empty0 Register
        __IO uint32_t EMP1;            // 0x0264 Empty1 Register
        __IO uint32_t EMP2;            // 0x0268 Empty2 Register

    } DCXO_TypeDef;

#define DCXO ((DCXO_TypeDef *)DCXO_BASE)

#ifdef __cplusplus
}
#endif