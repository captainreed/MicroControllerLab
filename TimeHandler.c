#include "TimeHandler.h"
#include "Keypad.h"

int currentKeypadValue = 0;
bool poundSignPressed = false;
bool stepperInPlace = false;

bool timerRunning;
void initTimeHandler()
{
timerRunning = false;
}

void HandleTime()
{
	//if the timer is not running allow the user to input a number from 1 to 59
//after pound has been pressed rotate the clock to the indicated position
//wait for pound to be pressed again
//while the timer is running do not accept new input from the user
//when the time has expired sound the buzzer for 1 second	
	if(!timerRunning)
	{
		scanKeypad();
		poundSignPressed = poundPressed();
		currentKeypadValue = getKeypadIntValue();
			if(poundSignPressed & !stepperInPlace)
			{
				poundSignPressed = false;
				//send the stepper to the right position
				//dont allow the user to input any more data untill the next cycle
				timerRunning = true;
			}
	}
}