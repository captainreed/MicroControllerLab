#include "ServoDriver.h"
#include "stm32l4xx.h"  

void initServo()
{
	GPIOB->MODER |= 0xFFFF5F5F;
	GPIOB->MODER &= 0x00005050;
	
	GPIOB->OTYPER &= 0xFFFFFF33;
	
	GPIOB->PUPDR &= 0xFFFF0F0F;
	
}

void setClockStartPosition(int location) // rotate the servo hand to the correct spot locaiton between 0 and 59
{
	/* HALF STEP POSITIONS
	AB',A,AB,B,A'B,A',A'B'
		
	AB' : 10000100 0x84
	A		: 00000100 0x4
	AB  : 01000100 0x44
	
	A'B : 01001000 0x48
	A'	: 00001000 0x8
	A'B': 10001000 0x88
	*/
	
	uint32_t HalfStepVals[6] =0x84 {0x84,0x4,0x44,0x48,0x8,0x88};
		
}

void runServo()//rotate the servo from its initial state to the 0 state in even intervals
{
	
}
