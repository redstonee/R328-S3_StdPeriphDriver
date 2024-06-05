#include "R328S3.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        __IO uint32_t PLL_CPUX_CTRL;       // 0x0000 PLL_CPUX Control Register
        uint32_t RESERVED0[0x3];           // 0x4 - 0xc Reserved
        __IO uint32_t PLL_DDR_CTRL;        // 0x0010 PLL_DDR Control Register
        uint32_t RESERVED1[0x3];           // 0x14 - 0x1c Reserved
        __IO uint32_t PLL_PERI0_CTRL;      // 0x0020 PLL_PERI0 Control Register
        uint32_t RESERVED2;                // 0x24 Reserved
        __IO uint32_t PLL_PERI1_CTRL;      // 0x0028 PLL_PERI1 Control Register
        uint32_t RESERVED3[0x13];          // 0x2c - 0x74 Reserved
        __IO uint32_t PLL_AUDIO_CTRL;      // 0x0078 PLL_AUDIO Control Register
        uint32_t RESERVED4[0x17];          // 0x7c - 0xd4 Reserved
        __IO uint32_t PLL_32K_CTRL;        // 0x00D8 PLL_32K Control Register
        uint32_t RESERVED5[0xd];           // 0xdc - 0x10c Reserved
        __IO uint32_t PLL_DDR_PAT_CTRL;    // 0x0110 PLL_DDR Pattern Control Register
        uint32_t RESERVED6[0x3];           // 0x114 - 0x11c Reserved
        __IO uint32_t PLL_PERI0_PAT0_CTRL; // 0x0120 PLL_PERI0 Pattern0 Control Register
        __IO uint32_t PLL_PERI0_PAT1_CTRL; // 0x0124 PLL_PERI0 Pattern1 Control Register
        __IO uint32_t PLL_PERI1_PAT0_CTRL; // 0x0128 PLL_PERI1 Pattern0 Control Register
        __IO uint32_t PLL_PERI1_PAT1_CTRL; // 0x012C PLL_PERI1 Pattern1 Control Register
        uint32_t RESERVED7[0x12];          // 0x130 - 0x174 Reserved
        __IO uint32_t PLL_AUDIO_PAT0_CTRL; // 0x0178 PLL_AUDIO Pattern0 Control Register
        __IO uint32_t PLL_AUDIO_PAT1_CTRL; // 0x017C PLL_AUDIO Pattern1 Control Register
        uint32_t RESERVED8[0x16];          // 0x180 - 0x1d4 Reserved
        __IO uint32_t PLL_32K_PAT0_CTRL;   // 0x01D8 PLL_32K Pattern0 Control Register
        __IO uint32_t PLL_32K_PAT1_CTRL;   // 0x01DC PLL_32K Pattern1 Control Register
        uint32_t RESERVED9[0x48];          // 0x1e0 - 0x2fc Reserved
        __IO uint32_t PLL_CPUX_BIAS;       // 0x0300 PLL_CPUX Bias Register
        uint32_t RESERVED10[0x3];          // 0x304 - 0x30c Reserved
        __IO uint32_t PLL_DDR_BIAS;        // 0x0310 PLL_DDR Bias Register
        uint32_t RESERVED11[0x3];          // 0x314 - 0x31c Reserved
        __IO uint32_t PLL_PERI0_BIAS;      // 0x0320 PLL_PERI0 Bias Register
        uint32_t RESERVED12;               // 0x324 Reserved
        __IO uint32_t PLL_PERI1_BIAS;      // 0x0328 PLL_PERI1 Bias Register
        uint32_t RESERVED13[0x13];         // 0x32c - 0x374 Reserved
        __IO uint32_t PLL_AUDIO_BIAS;      // 0x0378 PLL_AUDIO Bias Register
        uint32_t RESERVED14[0x17];         // 0x37c - 0x3d4 Reserved
        __IO uint32_t PLL_32K_BIAS;        // 0x03D8 PLL_32K Bias Register
        uint32_t RESERVED15[0x9];          // 0x3dc - 0x3fc Reserved
        __IO uint32_t PLL_CPUX_TUN;        // 0x0400 PLL_ CPUX Tuning Register
        uint32_t RESERVED16[0x3f];         // 0x404 - 0x4fc Reserved
        __IO uint32_t C0_CPUX_AXI_CFG;     // 0x0500 CPUX_AXI Configuration Register
        uint32_t RESERVED17[0x3];          // 0x504 - 0x50c Reserved
        __IO uint32_t PSI_AHB1_AHB2_CFG;   // 0x0510 PSI_AHB1_AHB2 Configuration Register
        uint32_t RESERVED18[0x2];          // 0x514 - 0x518 Reserved
        __IO uint32_t AHB3_CFG;            // 0x051C AHB3 Configuration Register
        __IO uint32_t APB1_CFG;            // 0x520 APB1 Configuration Register
        __IO uint32_t APB2_CFG;            // 0x524 APB2 Configuration Register
        uint32_t RESERVED19[0x56];         // 0x528 - 0x67c Reserved
        __IO uint32_t CE_CLK;              // 0x0680 CE Clock Register
        uint32_t RESERVED20[0x2];          // 0x684 - 0x688 Reserved
        __IO uint32_t CE_BGR;              // 0x068C CE Bus Gating Reset Register
        uint32_t RESERVED21[0x1f];         // 0x690 - 0x708 Reserved
        __IO uint32_t DMA_BGR;             // 0x070C DMA Bus Gating Reset Register
        uint32_t RESERVED22[0xb];          // 0x710 - 0x738 Reserved
        __IO uint32_t HSTIMER_BGR;         // 0x073C HSTIMER Bus Gating Reset Register
        __IO uint32_t AVS_CLK;             // 0x0740 AVS Clock Register
        uint32_t RESERVED23[0x12];         // 0x744 - 0x788 Reserved
        __IO uint32_t DBGSYS_BGR;          // 0x078C DBGSYS Bus Gating Reset Register
        uint32_t RESERVED24[0x3];          // 0x790 - 0x798 Reserved
        __IO uint32_t PSI_BGR;             // 0x079C PSI Bus Gating Reset Register
        uint32_t RESERVED25[0x3];          // 0x7a0 - 0x7a8 Reserved
        __IO uint32_t PWM_BGR;             // 0x07AC PWM Bus Gating Reset Register
        uint32_t RESERVED26[0x14];         // 0x7b0 - 0x7fc Reserved
        __IO uint32_t DRAM_CLK;            // 0x0800 DRAM Clock Register
        __IO uint32_t MBUS_MAT_CLK_GATING; // 0x0804 MBUS Master Clock Gating Register
        uint32_t RESERVED27;               // 0x808 Reserved
        __IO uint32_t DRAM_BGR;            // 0x080C DRAM Bus Gating Reset Register
        uint32_t RESERVED28[0x9];          // 0x810 - 0x830 Reserved
        __IO uint32_t SMHC1_CLK;           // 0x0834 SMHC1 Clock Register
        uint32_t RESERVED29[0x5];          // 0x838 - 0x848 Reserved
        __IO uint32_t SMHC_BGR;            // 0x084C SMHC Bus Gating Reset Register
        uint32_t RESERVED30[0x2f];         // 0x850 - 0x908 Reserved
        __IO uint32_t UART_BGR;            // 0x090C UART Bus Gating Reset Register
        uint32_t RESERVED31[0x3];          // 0x910 - 0x918 Reserved
        __IO uint32_t TWI_BGR;             // 0x091C TWI Bus Gating Reset Register
        uint32_t RESERVED32[0x8];          // 0x920 - 0x93c Reserved
        __IO uint32_t SPI0_CLK;            // 0x0940 SPI0 Clock Register
        __IO uint32_t SPI1_CLK;            // 0x0944 SPI1 Clock Register
        uint32_t RESERVED33[0x9];          // 0x948 - 0x968 Reserved
        __IO uint32_t SPI_BGR;             // 0x096C SPI Bus Gating Reset Register
        uint32_t RESERVED34[0x1f];         // 0x970 - 0x9e8 Reserved
        __IO uint32_t GPADC_BGR;           // 0x09EC GPADC Bus Gating Reset Register
        uint32_t RESERVED35[0x3];          // 0x9f0 - 0x9f8 Reserved
        __IO uint32_t THS_BGR;             // 0x09FC THS Bus Gating Reset Register
        uint32_t RESERVED36[0x4];          // 0xa00 - 0xa0c Reserved
        __IO uint32_t PCM0_CLK;            // 0x0A10 I2S/PCM0 Clock Register
        __IO uint32_t PCM1_CLK;            // 0x0A14 I2S/PCM1 Clock Register
        __IO uint32_t PCM2_CLK;            // 0x0A18 I2S/PCM2 Clock Register
        __IO uint32_t PCM_BGR;             // 0x0A1C I2S/PCM Bus Gating Reset Register
        __IO uint32_t OWA_CLK;             // 0x0A20 OWA Clock Register
        uint32_t RESERVED37[0x2];          // 0xa24 - 0xa28 Reserved
        __IO uint32_t OWA_BGR;             // 0x0A2C OWA Bus Gating Reset Register
        uint32_t RESERVED38[0x4];          // 0xa30 - 0xa3c Reserved
        __IO uint32_t DMIC_CLK;            // 0x0A40 DMIC Clock Register
        uint32_t RESERVED39[0x2];          // 0xa44 - 0xa48 Reserved
        __IO uint32_t DMIC_BGR;            // 0x0A4C DMIC Bus Gating Reset Register
        __IO uint32_t AUDIO_CODEC_1X_CLK;  // 0x0A50 AUDIO CODEC 1X Clock Register
        __IO uint32_t AUDIO_CODEC_4X_CLK;  // 0x0A54 AUDIO CODEC 4X Clock Register
        uint32_t RESERVED40;               // 0xa58 Reserved
        __IO uint32_t AUDIO_CODEC_BGR;     // 0x0A5C AUDIO CODEC Bus Gating Reset Register
        uint32_t RESERVED41[0x4];          // 0xa60 - 0xa6c Reserved
        __IO uint32_t USB0_CLK;            // 0x0A70 USB0 Clock Register
        uint32_t RESERVED42[0x6];          // 0xa74 - 0xa88 Reserved
        __IO uint32_t USB_BGR;             // 0x0A8C USB Bus Gating Reset Register
        uint32_t RESERVED43[0xf];          // 0xa90 - 0xac8 Reserved
        __IO uint32_t VAD_BGR;             // 0x0ACC VAD Bus Gating Reset Register
        __IO uint32_t LPSD_CLK;            // 0x0AD0 LPSD Clock Register
        uint32_t RESERVED44[0x2];          // 0xad4 - 0xad8 Reserved
        __IO uint32_t LPSD_BGR;            // 0x0ADC LPSD Bus Gating Reset Register
        uint32_t RESERVED45[0x44];         // 0xae0 - 0xbec Reserved
        __IO uint32_t LEDC_CLK;            // 0x0BF0 LEDC Clock Register
        uint32_t RESERVED46[0x2];          // 0xbf4 - 0xbf8 Reserved
        __IO uint32_t LEDC_BGR;            // 0x0BFC LEDC BUS GATING RESET Register
        uint32_t RESERVED47[0xc0];         // 0xc00 - 0xefc Reserved
        __IO uint32_t CCU_SEC_SWITCH;      // 0x0F00 CCU Security Switch Register
        __IO uint32_t PLL_LOCK_DBG_CTRL;   // 0x0F04 PLL Lock Debug Control Register
        uint32_t RESERVED48[0x6];          // 0xf08 - 0xf1c Reserved
        __IO uint32_t PLL_CPUX_HW_FM;      // 0x0F20 PLL_CPUX Hardware FM Register
        uint32_t RESERVED49[0x3];          // 0xf24 - 0xf2c Reserved
        __IO uint32_t MOD_SPE_CLK;         // 0x0F30 Module Special Clock Register
        uint32_t RESERVED50[0x3];          // 0xf34 - 0xf3c Reserved
        __IO uint32_t HOSC_OUTPUT_CTRL;    // 0x0F40 HOSC Output Control Register
    } CCU_TypeDef;

#define CCU ((CCU_TypeDef *)CCU_BASE)

#define CCU_UART_Deassert_Reset(UARTx) CCU->UART_BGR |= (1 << (UARTx + 16))
#define CCU_UART_Open_Gate_Clocking(UARTx) CCU->UART_BGR |= (1 << UARTx)

#ifdef __cplusplus
}
#endif