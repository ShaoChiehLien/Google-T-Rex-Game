#include "stm32f0xx.h"
#include "stm32f0_discovery.h"
#include <math.h>
#include "sound.h"

void initSound(void)
{
    initDAC();
    initDMA();
    initTIM15();
}


void genWave (void)
{
    for(int x = 0; x < sizeof wavetable / sizeof wavetable[0]; x++)
    {
        wavetable[x] = 32767 * sin(x * 2 * M_PI / 256);
    }
}

void initTIM15(void)
{
    //1. Enable timer 15 in RCC
    RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;

    //2. Set PSC and ARR for 160 kHz
    TIM15->PSC = 150-1;
    TIM15->ARR = 2-1;

    //3. Enable the counter
    TIM15->CR1 |= TIM_CR1_CEN;

    //7. Enable Auto-Preload
    TIM15->CR1 |= TIM_CR1_ARPE;

    //6. MMS for update event is selected for 010: Update - The update event is selected as trigger output (TRGO).
    TIM15->CR2 &= ~(TIM_CR2_MMS);
    TIM15->CR2 |= TIM_CR2_MMS_1;

    //4.
    TIM15->DIER |= TIM_DIER_UDE;
}

void initDMA(void)
{
    //Create Wavetable
    genWave();

    //Enable the peripheral clock on DMA
    RCC->AHBENR |= RCC_AHBENR_DMA1EN;

    //Set the peripheral data register address
    //DMAX-ChannelX->CPAR
    DMA1_Channel5->CPAR = (uint32_t) (&(DAC->DHR12R1));

    //Set the memory address to mem region for wavetable
    DMA1_Channel5->CMAR = (uint32_t)wavetable;

    //Set count to number of elements in wavetable
    DMA1_Channel5->CNDTR = sizeof wavetable / sizeof wavetable[0];

    //Set Direction of Copy (DMA_CCRx: DIR)
    DMA1_Channel5->CCR |= DMA_CCR_DIR;

    //Circular Transfer
    DMA1_Channel5->CCR |= DMA_CCR_CIRC;

    //MSIZE
    DMA1_Channel5->CCR &= ~(DMA_CCR_MSIZE);
    DMA1_Channel5->CCR |= DMA_CCR_MSIZE_0;

    //PSIZE
    DMA1_Channel5->CCR &= ~(DMA_CCR_PSIZE);
    DMA1_Channel5->CCR |= DMA_CCR_PSIZE_0;

    //Set MINC
    DMA1_Channel5->CCR |= DMA_CCR_MINC;

    //Enable DMA Channel 5
    DMA1_Channel5->CCR |= DMA_CCR_EN;

    //Enable the interrupt to be triggered by timer15
    NVIC_EnableIRQ(DMA1_Channel4_5_IRQn);
}

void initDAC(void)
{
    //Enable perif clock to DAC
    RCC->APB1ENR |= RCC_APB1ENR_DACEN;

    //Set up GPIO for DAC (PA4)
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    //Set PA4 for Analog mode
    GPIOA->MODER |= GPIO_MODER_MODER4;

    //Disable DAC ch1
    DAC->CR &= ~DAC_CR_EN1;

    //Trigger is enabled
    DAC->CR |= DAC_CR_TEN1;

    //DAC Trigger selection:
    //Triggered by Timer 15 TRGO event
    DAC->CR &= ~DAC_CR_TSEL1;
    DAC->CR |= DAC_CR_TSEL1_0 | DAC_CR_TSEL1_1;

    //DAC Channel1 Enabled
    //DAC->CR |= DAC_CR_EN1;

}
