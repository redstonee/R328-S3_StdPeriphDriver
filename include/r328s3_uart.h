#include "R328S3.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        __IO uint32_t RBR_THR_DLL;      /*!< 0x00 Receiver Buffer, Transmitter Holding or Divisor Latch Low */
        __IO uint32_t IER_DLH;          /*!< 0x04 Interrupt Enable or Divisor Latch High */
        __IO uint32_t IIR_FCR;          /*!< 0x08 Interrupt Identification or FIFO Control */
        __IO uint32_t LCR;              /*!< 0x0C Line Control */
        __IO uint32_t MCR;              /*!< 0x10 Modem Control */
        __IO uint32_t LSR;              /*!< 0x14 Line Status */
        __IO uint32_t MSR;              /*!< 0x18 Modem Status */
        __IO uint32_t SCH;              /*!< 0x1C Scratch */
        uint32_t RESERVED0[0x17];       /*!< 0x20 - 0x78 Reserved */
        __IO uint32_t USR;              /*!< 0x7C UART Status */
        __IO uint32_t TFL;              /*!< 0x80 Transmit FIFO Level */
        __IO uint32_t RFL;              /*!< 0x84 Receive FIFO Level */
        __IO uint32_t HSK;              /*!< 0x88 UART Handshake */
        uint32_t RESERVED1[0x6];        /*!< 0x8C - 0xA0 Reserved */
        __IO uint32_t HALT;             /*!< 0xA4 UART Halt TX */
        uint32_t RESERVED2[0x2];        /*!< 0xA8 - 0xAC Reserved */
        __IO uint32_t DBG_DLL;          /*!< 0xB0 Debug Divisor Latch Low */
        __IO uint32_t DBG_DLH;          /*!< 0xB4 Debug Divisor Latch High */
        uint32_t RESERVED3[0x2];        /*!< 0xB8 - 0xBC Reserved */
        __IO uint32_t RS485_CTL;        /*!< 0xC0 RS485 Control */
        __IO uint32_t RS485_ADDR_MATCH; /*!< 0xC4 RS485 Address Match */
        __IO uint32_t BUS_IDLE_CHK;     /*!< 0xC8 Bus Idle Check */
        __IO uint32_t TX_DLY;           /*!< 0xCC TX Delay */
    } UART_TypeDef;

    typedef enum
    {
        UART_DataLen_5 = 0,
        UART_DataLen_6,
        UART_DataLen_7,
        UART_DataLen_8
    } UART_DataLen_TypeDef;

    typedef enum
    {
        UART_StopBits_1 = 0, // 1 stop bit
        UART_StopBits_2      // 1.5 stop bits when data length is 5 bits, otherwise 2 stop bits
    } UART_StopBits_TypeDef;

    typedef enum
    {
        UART_Parity_Odd = 1, // Odd parity
        UART_Parity_None,    // No parity
        UART_Parity_Even     // Even parity
    } UART_Parity_TypeDef;

    typedef enum
    {
        UART_Mode_UART = 0, // UART mode
        UART_Mode_IRDA,     // IrDA mode
        UART_Mode_RS485     // RS485 mode
    } UART_Mode;

    typedef struct
    {
        uint32_t BaudRate;              /*!< This member configures the UART communication baud rate */
        UART_DataLen_TypeDef DataLen;   /*!< Specifies the number of data bits transmitted or received in a frame */
        UART_StopBits_TypeDef StopBits; /*!< Specifies the number of stop bits transmitted */
        UART_Parity_TypeDef Parity;     /*!< Specifies the parity mode */
        UART_Mode Mode;                 /*!< Specifies the UART mode */
    } UART_InitTypeDef;

#define UART0 ((UART_TypeDef *)UART0_BASE)
#define UART1 ((UART_TypeDef *)UART1_BASE)
#define UART2 ((UART_TypeDef *)UART2_BASE)
#define UART3 ((UART_TypeDef *)UART3_BASE)

#define UART_Divisor_Latch(UARTx, en) (en ? (UARTx->LCR |= 0x80) : (UARTx->LCR &= ~0x80))
#define UART_EnableChangeWhenBusy(UARTx) (UARTx->HALT |= 0x02)
#define UART_UpdateChange(UARTx) (UARTx->HALT |= 0x04)
#define UART_SetAutoFlowControl(UARTx, en) (en ? (UARTx->MCR |= 0x20) : (UARTx->MCR &= ~0x20))
#define UART_SetRTS(UARTx, en) (en ? (UARTx->MCR |= 0x2) : (UARTx->MCR &= ~0x2)) // Request to send, active low
#define UART_SetDTR(UARTx, en) (en ? (UARTx->MCR |= 0x1) : (UARTx->MCR &= ~0x1)) // Data terminal ready, active low

#define UART_GetDataReady(UARTx) (UARTx->LSR & 0x1)
#define UART_GetOverrunError(UARTx) (UARTx->LSR & 0x2)
#define UART_GetParityError(UARTx) (UARTx->LSR & 0x4)
#define UART_GetFramingError(UARTx) (UARTx->LSR & 0x8)
#define UART_GetBreakInterrupt(UARTx) (UARTx->LSR & 0x10)
#define UART_GetTXHoldingEmpty(UARTx) (UARTx->LSR & 0x20)
#define UART_GetTXEmpty(UARTx) (UARTx->LSR & 0x40)
#define UART_GetRXFIFOError(UARTx) (UARTx->LSR & 0x80)

#define UART_EnableFIFOs(UARTx) (UARTx->IIR_FCR |= 0x1)
#define UART_ClearRXFIFO(UARTx) (UARTx->IIR_FCR |= 0x2)
#define UART_ClearTXFIFO(UARTx) (UARTx->IIR_FCR |= 0x4)

    void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct);
    void UART_StructInit(UART_InitTypeDef *UART_InitStruct);

    void UART_WriteByte(UART_TypeDef *UARTx, uint8_t byte);
    uint8_t UART_ReadByte(UART_TypeDef *UARTx);

    void UART_WriteData(UART_TypeDef *UARTx, uint8_t *data, uint32_t len);
    void UART_Printf(UART_TypeDef *UARTx, const char *format, ...);

#ifdef __cplusplus
}
#endif