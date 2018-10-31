#include "PiezoBuzzer.h"
#include "stm32l4xx.h"                  // Device header

void initBuzzer()
{
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;//turn on port E clock
	//set PIN PE8 to be drain on the buzzer
	GPIOE->MODER &= ~GPIO_MODER_MODE15_1 ;//set to alternate function
	GPIOE->MODER |= GPIO_MODER_MODE15_0 ;//set to alternate function
	//to change the pin if PA7 is needed else where check appendix I in the back of the book for TIM1_CH1N
	/*GPIOE->AFR[1] |= GPIO_AFRH_AFSEL8_0;//selecting alternate function to be alternate function 1
	GPIOE->AFR[1] &= ~GPIO_AFRH_AFSEL8_1;//selecting alternate function to be alternate function 1
	GPIOE->AFR[1] &= ~GPIO_AFRH_AFSEL8_2;//selecting alternate function to be alternate function 1
	GPIOE->AFR[1] &= ~GPIO_AFRH_AFSEL8_3;//selecting alternate function to be alternate function 1
	//other potential pints are PB13 PE8 
	//if PB13 is used AFRL is replaced AFRH
	*/
	//there might be more potential pins but it would take altering more of the example code from the book
	GPIOE->PUPDR &= ~GPIO_PUPDR_PUPD15_0;//set to no push pull
	GPIOE->PUPDR &= ~GPIO_PUPDR_PUPD15_1;//set to no push pull
	GPIOE->OTYPER &= ~GPIO_OTYPER_OT15;// concerned this is incorrect if problems occour check value against stm file values to be sure
	//GPIOA->ODR |= GPIO_ODR_OD7; //set buzzer to be off
	//this block of coode follows example in textbook on page 395
	/*RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; //enable timer 1 clock
	TIM1->CR1 |= TIM_CR1_DIR; //select counting up
	TIM1->PSC = 3999; // set timer frequency to 1000Hz
	TIM1->ARR = 999; // pwm period = 999+1 = 1000
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M; //clear output compare mode bit for channel 1
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_1; //select mode 1 for channel 1
	TIM1->CCMR1 |= TIM_CCMR1_OC1PE; // preload enable on output 1
	TIM1->CCER &= ~TIM_CCER_CC1NP; // select active hgih
	TIM1->CCER |= TIM_CCER_CC1NE; // enable complementary output
	TIM1->BDTR |= TIM_BDTR_MOE; //enable main output
	TIM1->CCR1 = 660; //set duty cycle*/
	//TIM1->CR1 |= TIM_CR1_CEN; // enable counter
	// end of block
}

void soundBuzzer(int time)
{
	//TIM1->CR1 |= TIM_CR1_CEN; // enable counter
	for (int count = 0; count < time; count++)
	{
	 for (int delay = 0; delay < 35; delay++)
	 {
		 GPIOE->ODR |= GPIO_ODR_OD15;
		 for (int stall = 0; stall < 8000; stall++)
			{
				(void)0;
			}
		 GPIOE->ODR &= ~GPIO_ODR_OD15;
		 for (int stall = 0; stall < 8000; stall++)
			{
				(void)0;
			}
  }
	 for (int spacing = 0; spacing <= 35*16000; spacing++)
	{
		(void)0;
	}
	//TIM1->CR1 &= ~TIM_CR1_CEN; // disable counter
	}
}	
