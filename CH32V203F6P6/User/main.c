/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : Kozodoy Andrey, Takhvatulin Mikhail, Schetinin Stanislav and Mikhaylov Pavel
 * Version            : V1.0.0
 * Date               : 28.11.2024
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) Kozodoy Andrey, Takhvatulin Mikhail, Schetinin Stanislav and Mikhaylov Pavel.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller ch32
 *******************************************************************************/

#include "ch32v20x.h"
/* Global typedef */

/* Global define */

/* Global Variable */

void setADC(void)
{
    RCC->CFGR0 &= ~RCC_ADCPRE;
    RCC->APB2PCENR |= RCC_ADC2EN;
    while(!(RCC->APB2PCENR & RCC_ADC2EN));
    ADC2->CTLR1 |= ADC_EOCIE | ADC_SCAN;
    ADC2->CTLR2 |= ADC_ALIGN | ADC_CONT | ADC_JSWSTART;
    ADC2->ISQR = ((2-1) << 20) | (1 << 10) | (9<<15); // ���ڧ֧� �էѧߧߧ��� �� �էӧ�� �ܧѧߧѧݧ��: 1 �� 9 (PA1 �� PB1)

    ADC2->CTLR2 |= ADC_ADON;
}

__attribute__((interrupt("WCH-Interrupt-fast")))
void ADC1_2_IRQHandler(void)
{
    uint16_t r1 = ADC1->IDATAR3;
    uint16_t r2 = ADC1->IDATAR4;
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
//    setClock();
    setADC();
    NVIC_EnableIRQ(ADC1_2_IRQn);
    while(1)
    {
    }
}
