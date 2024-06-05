#include "r328s3_uart.h"
#include "r328s3_ccu.h"
#include "system_r328s3.h"
#include <stdarg.h>
#include <string.h>

void UART_StructInit(UART_InitTypeDef *UART_InitStruct)
{
    UART_InitStruct->BaudRate = 9600;
    UART_InitStruct->DataLen = UART_DataLen_8;
    UART_InitStruct->StopBits = UART_StopBits_1;
    UART_InitStruct->Parity = UART_Parity_None;
    UART_InitStruct->Mode = UART_Mode_UART;
}

void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct)
{
    switch ((uint32_t)UARTx)
    {
    case (uint32_t)UART0:
        CCU_UART_Deassert_Reset(0);
        CCU_UART_Open_Gate_Clocking(0);
        break;

    case (uint32_t)UART1:
        CCU_UART_Deassert_Reset(1);
        CCU_UART_Open_Gate_Clocking(1);
        break;

    case (uint32_t)UART2:
        CCU_UART_Deassert_Reset(2);
        CCU_UART_Open_Gate_Clocking(2);
        break;

    case (uint32_t)UART3:
        CCU_UART_Deassert_Reset(3);
        CCU_UART_Open_Gate_Clocking(3);
        break;
    }

    uint32_t divisor = (SystemCoreClock / 16) / UART_InitStruct->BaudRate;
    UART_EnableChangeWhenBusy(UARTx);
    UART_Divisor_Latch(UARTx, 1);
    UARTx->RBR_THR_DLL = divisor & 0xFF;
    UARTx->IER_DLH = (divisor >> 8) & 0xFF;
    UART_Divisor_Latch(UARTx, 0);
    UART_UpdateChange(UARTx);

    UARTx->MCR &= 0xC0;                       // Clear the mode bits
    UARTx->MCR |= UART_InitStruct->Mode << 6; // Set the mode bits

    UARTx->LCR &= ~0x1f;
    UARTx->LCR |= UART_InitStruct->DataLen |
                  (UART_InitStruct->StopBits << 2) |
                  (UART_InitStruct->Parity << 3);

    UART_EnableFIFOs(UARTx);
}

void UART_WriteByte(UART_TypeDef *UARTx, uint8_t byte)
{
    while (!UART_GetTXEmpty(UARTx))
        ;
    UARTx->RBR_THR_DLL = byte;
}

void UART_WriteData(UART_TypeDef *UARTx, uint8_t *data, uint32_t len)
{
    while (len--)
        UART_WriteByte(UARTx, *data++);
}

void UART_Printf(UART_TypeDef *UARTx, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char buffer[256];
    vsprintf(buffer, format, args);
    va_end(args);
    UART_WriteData(UARTx, (uint8_t *)buffer, strlen(buffer));
}

uint8_t UART_ReadByte(UART_TypeDef *UARTx)
{
    if (!UART_GetDataReady(UARTx))
        return 0;
    return UARTx->RBR_THR_DLL;
}