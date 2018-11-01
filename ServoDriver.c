#include "ServoDriver.h"
#include "stm32l476xx.h"

int setDelay = 4000;     //Changing this will change delay for winding up the clock
int runDelay = 32000;		//Changing this will change delay for running the clock from set position

/* HALF STEP POSITIONS
	AB',A,AB,B,A'B,A',A'B', B'
		
	AB' : 10000100 0x84
	A		: 00000100 0x4
	AB  : 01000100 0x44
	B		: 01000000 0x40
	A'B : 01001000 0x48
	A'	: 00001000 0x8
	A'B': 10001000 0x88
	B'	: 10000000 0x80
	*/

uint32_t HalfStepORVals[8] ={0x00000084,0x00000004,0x00000044,0x00000040,0x00000048,0x00000008,0x00000088,0x00000080};
uint32_t HalfStepANDVals[8] ={0xFFFF0084,0xFFFF0004,0xFFFF0044,0xFFFF0040,0xFFFF0048,0xFFFF0008,0xFFFF0088,0xFFFF0080};

/* SINGLE STEP POSITIONS
	A,A',B,B'
		
	A		: 00000100 0x4
	A'	: 00001000 0x8
	B		: 01000000 0x40
	B'	: 10000000 0x80
	*/

uint32_t SingleStepORVals[4] ={0x00000004,0x00000008,0x00000040,0x00000080};
uint32_t SingleStepANDVals[4] ={0xFFFFFF37,0xFFFFFF3B,0xFFFFFF7F,0xFFFFFFB3};

void initServo()
{
	GPIOB->MODER &= 0xFFFF5F5F;
	GPIOB->MODER |= 0x00005050;
	
	GPIOB->OTYPER &= 0xFFFFFF33;
	
	GPIOB->PUPDR &= 0xFFFF0F0F;
	
}

void setClockStartPosition(int location) // rotate the servo hand to the correct spot locaiton between 0 and 59
{
	float fCycles = location * ( 512 / 60 );
	int numCycles = (int)(fCycles + .5);
	
	for (int i = 0; i < numCycles; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GPIOB->ODR &= SingleStepANDVals[j];
			GPIOB->ODR |= SingleStepORVals[j];
			delay(setDelay);
		}
		
		
	}
}

void runServo(int location)//rotate the servo from its initial state to the 0 state in even intervals
{
	float fCycles = location * ( 512 / 60 );
	int numCycles = (int)(fCycles + .5);
	
	for (int i = 0; i < numCycles; i++)
	{
		for (int j = 4; j > 0; j--)
		{
			GPIOB->ODR &= SingleStepANDVals[j-1];
			GPIOB->ODR |= SingleStepORVals[j-1];
			delay(runDelay);
		}
		
	}
}

void delay(int delayVal)
{
	for (int i = 0; i < delayVal; i++)
	{
		(void)0;
	}
}
