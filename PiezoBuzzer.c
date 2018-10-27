#include "PiezoBuzzer.h"
#include "stm32l4xx.h"                  // Device header

void initBuzzer()
{
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;//turn on port A clock
	//set PIN PC14 to be drain on the buzzer
	GPIOA->MODER &= ~GPIO_MODER_MODE7_0 ;//set to alternate function
	GPIOA->MODER |= GPIO_MODER_MODE7_1 ;//set to alternate function
	//to change the pin if PA7 is needed else where check appendix I in the back of the book for TIM1_CH1N
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL7_0;//selecting alternate function to be alternate function 1
	GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL7_1;//selecting alternate function to be alternate function 1
	GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL7_2;//selecting alternate function to be alternate function 1
	GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL7_3;//selecting alternate function to be alternate function 1
	//other potential pints are PB13 PE8 
	//if PB13 is used AFRL is replaced AFRH
	//there might be more potential pins but it would take altering more of the example code from the book
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD7_0;//set to no push pull
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD7_1;//set to no push pull
	GPIOA->OTYPER |= GPIO_OTYPER_ODR_7;// concerned this is incorrect if problems occour check value against stm file values to be sure
	//GPIOA->ODR |= GPIO_ODR_OD7; //set buzzer to be off
	//this block of coode follows example in textbook on page 395
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; //enable timer 1 clock
	TIM1->CR1 |= TIM_CR1_DIR; //select counting up
	TIM1->PSC = 3999; // set timer frequency to 1000Hz
	TIM1->ARR = 999; // pwm period = 999+1 = 1000
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M; //clear output compare mode bit for channel 1
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_1; //select mode 1 for channel 1
	TIM1->CCMR1 |= TIM_CCMR1_OC1PE; // preload enable on output 1
	TIM1->CCER &= ~TIM_CCER_CC1NP; // select active hgih
	TIM1->CCER |= TIM_CCER_CC1NE; // enable complementary output
	TIM1->BDTR |= TIM_BDTR_MOE; //enable main output
	TIM1->CCR1 = 660; //set duty cycle
	//TIM1->CR1 |= TIM_CR1_CEN; // enable counter
	// end of block
}

void soundBuzzer(int time)
{
	TIM1->CR1 |= TIM_CR1_CEN; // enable counter
	//GPIOA->ODR &= ~GPIO_ODR_OD7;
	for (int delay = 0; delay < time; delay++)
	{
		(void)0;
	}
	//GPIOA->ODR |= GPIO_ODR_OD7;
	TIM1->CR1 &= ~TIM_CR1_CEN; // disable counter
}
