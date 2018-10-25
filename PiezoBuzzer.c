#include "PiezoBuzzer.h"

void initBuzzer()
{
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;//turn on port C clock
	//set PIN PC14 to be drain on the buzzer
	GPIOC->MODER |= GPIO_MODER_MODE14_0 ;//set to alternate function
	GPIOC->MODER |= GPIO_MODER_MODE14_1 ;//set to alternate function
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD14_0;//set to no push pull
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD14_1;//set to no push pull
	GPIOC->OTYPER |= GPIO_OTYPER_ODR14;// concerned this is incorrect
	GPIOC->ODR |= GPIO_ODR_OD14; //set buzzer to be off
	//this block of coode follows example in textbook on page 395
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	TIM1->CR1 |= TIM_CR1_DIR;
	TIM1->PSC = 39;
	TIM1->ARR = 999;
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_1;
	TIM1->CCMR1 |= TIM_CCMR1_OC1PE;
	TIM1->CCER &= ~TIM_CCER_CC1NP;
	TIM1->CCER |= TIM_CCER_CC1NE;
	TIM->BDTR |= TIM_BDTR_MOE;
	TIM1->CCR1 = 500;
	TIM1->CR1 |= TIM_CR1_CEN;
	// end of block
}

void soundBuzzer(int time)
{
	GPIOC->ODR &= ~GPIO_ODR_OD14;
	for (int delay = 0; delay < time; delay++)
	{
		(void)0;
	}
	GPIOC->ODR |= GPIO_ODR_OD14;
}
