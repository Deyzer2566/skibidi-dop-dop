/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *USART Print debugging routine:
 *USART1_Tx(PA9).
 *This example demonstrates using USART1(PA9) as a print debug port output.
 *
 */

#include "debug.h"
#include "ch32v20x.h"
/* Global typedef */

/* Global define */

/* Global Variable */
void setTimer()
{
    RCC->APB2PCENR |= RCC_IOPAEN;
    while((RCC->APB2PCENR & RCC_IOPAEN) != RCC_IOPAEN);
    GPIOA->CFGLR &= ~(0b100);
    GPIOA->CFGLR |= (0b01)|(0b10<<2);

    RCC->APB1PCENR |= RCC_TIM2EN;
    while((RCC->APB1PCENR & RCC_TIM2EN) != RCC_TIM2EN);
    TIM2->CHCTLR1 = (0b110<<4);
    TIM2->PSC = 1-1;
    TIM2->ATRLR = 256;
    TIM2->CH1CVR = 0;
    TIM2->CCER |= 1;
    TIM2->CTLR1 |= TIM_CEN;

    RCC->APB1PCENR |= RCC_TIM3EN;
    while((RCC->APB1PCENR & RCC_TIM3EN) != RCC_TIM3EN);
    TIM3->PSC = 545-1;
    TIM3->ATRLR = 1;
    TIM3->CTLR1 |= TIM_URS;
    TIM3->DMAINTENR |= TIM_UIE;
    TIM3->CTLR1 |= TIM_CEN;
}

void setUart()
{
    RCC->APB2PCENR |= RCC_IOPAEN;
    while((RCC->APB2PCENR & RCC_IOPAEN) != RCC_IOPAEN);
    GPIOA->CFGLR &= ~(1<<14);
    GPIOA->CFGLR |= 1<<15;

    RCC->APB1PCENR |= RCC_USART2EN;
    USART2->BRR = (2<<4)|(1<<3); // 600.000 baud
    USART2->CTLR1 |= USART_CTLR1_UE | USART_CTLR1_RXNEIE | USART_CTLR1_RE;
}

uint8_t audio[5000];
uint16_t audio_ptr = 0;
uint16_t cur_audio = 0;

__attribute__((interrupt("WCH-Interrupt-fast")))
void USART2_IRQHandler(void)
{
    if(USART2->STATR & USART_STATR_RXNE)
    {
        audio[audio_ptr++] = USART2->DATAR;
        audio_ptr %= 5000;
    }
}

__attribute__((interrupt("WCH-Interrupt-fast")))
void TIM3_IRQHandler(void)
{
    TIM2->CH1CVR = audio[cur_audio++];
    cur_audio %= 5000;
    TIM3->INTFR &= ~1;
}

void setClock()
{
    RCC->CFGR0 |= 1<<18; // pll = 3*hsi
    while((RCC->CFGR0 & (1<<18)) != (1<<18));
    EXTEN->EXTEN_CTR |= EXTEN_PLL_HSI_PRE;
    RCC->CTLR |= 1<<24; // pllon
        while((RCC->CTLR & (1<<24)) != (1<<24));
    RCC->CFGR0 |= 2; // pll for sysclk
    while((RCC->CFGR0 & (2)) != (2));
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    NVIC_EnableIRQ(USART2_IRQn);
    NVIC_EnableIRQ(TIM3_IRQn);
    Delay_Init();
//    USART_Printf_Init(115200);
    setClock();
    setTimer();
    setUart();
    SystemCoreClockUpdate();
//    printf("SystemClk:%d\r\n", SystemCoreClock);
//    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
//    printf("This is printf example\r\n");

    while(1)
    {
    }
}