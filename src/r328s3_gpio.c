#include "r328s3_gpio.h"

void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct)
{
    uint32_t pos = 0x00, currentpin = 0x00;

    /*------------------------- GPIO Mode Configuration ---------------------*/
    for (uint8_t pinpos = 0; pinpos < 8; pinpos++) // GPIO 0-7
    {
        pos = ((uint32_t)0x01) << pinpos;
        /* Get the port pins position */
        currentpin = (GPIO_InitStruct->Pin) & pos;

        if (currentpin == pos)
        {
            GPIOx->CFG0 &= ~(0x7 << (pinpos << 2));                          // Clear the bits
            GPIOx->CFG0 |= (GPIO_InitStruct->Mode << (pinpos << 2));         // Set the bits
            GPIOx->DRV0 &= ~(0x3 << (pinpos << 1));                          // Clear the bits
            GPIOx->DRV0 |= (GPIO_InitStruct->Strength << (pinpos << 1));     // Set the bits
            GPIOx->PULL0 &= ~(0x3 << (pinpos << 1));                         // Clear the bits
            GPIOx->PULL0 |= (GPIO_InitStruct->GPIO_Pull << (pinpos << 1)); // Set the bits
        }
    }
    for (uint8_t pinpos = 8; pinpos < 16; pinpos++) // GPIO 8-15
    {
        pos = ((uint32_t)0x01) << pinpos;
        /* Get the port pins position */
        currentpin = (GPIO_InitStruct->Pin) & pos;

        if (currentpin == pos)
        {
            GPIOx->CFG1 &= ~(0x7 << ((pinpos - 8) << 2));                    // Clear the bits
            GPIOx->CFG1 |= (GPIO_InitStruct->Mode << ((pinpos - 8) << 2));   // Set the bits
            GPIOx->DRV0 &= ~(0x3 << (pinpos << 1));                          // Clear the bits
            GPIOx->DRV0 |= (GPIO_InitStruct->Strength << (pinpos << 1));     // Set the bits
            GPIOx->PULL0 &= ~(0x3 << (pinpos << 1));                         // Clear the bits
            GPIOx->PULL0 |= (GPIO_InitStruct->GPIO_Pull << (pinpos << 1)); // Set the bits
        }
    }
    if (GPIO_InitStruct->Pin == GPIO_Pin_16) // GPIOC only
    {
        GPIOx->CFG2 = GPIO_InitStruct->Mode;
        GPIOx->DRV1 = GPIO_InitStruct->Strength;
        GPIOx->PULL1 = GPIO_InitStruct->GPIO_Pull;
    }
}

void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct)
{
    /* Reset GPIO init structure parameters values */
    GPIO_InitStruct->Pin = GPIO_Pin_None;
    GPIO_InitStruct->Mode = GPIO_Mode_IN;
    GPIO_InitStruct->GPIO_Pull = GPIO_NoPull;
    GPIO_InitStruct->Strength = GPIO_Strength_L0;
}

void EINT_SetTriggerMode(EINT_TypeDef *PnEINT, uint8_t GPIO_Pin, EINT_TriggerMode mode)
{
    for (uint8_t i = 0; i < 8; i++) // GPIO 0-7
    {
        if (GPIO_Pin & (1 << i))
        {
            PnEINT->CFG0 &= ~(0xf << (i << 2)); // Clear the trigger mode bits
            PnEINT->CFG0 |= mode << (i << 2);   // Set the mode
        }
    }
    for (uint8_t i = 8; i < 16; i++) // GPIO 8-15
    {
        if (GPIO_Pin & (1 << i))
        {
            PnEINT->CFG1 &= ~(0xf << ((i - 8) << 2)); // Clear the trigger mode bits
            PnEINT->CFG1 |= mode << ((i - 8) << 2);   // Set the mode
        }
    }
    if (GPIO_Pin & (1 << 16)) // GPIO 16, GPIOC only
    {
        PnEINT->CFG2 &= ~(0xf); // Clear the trigger mode bits
        PnEINT->CFG2 |= mode;   // Set the mode
    }
    
}