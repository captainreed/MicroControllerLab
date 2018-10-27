#include "TimeHandler.h"
#include "Keypad.h"
#include "ServoDriver.h"

int currentKeypadValue = 0;
bool poundSignPressed = false;
bool stepperInPlace = false;
bool timerAwaitingStart = false; //this flag will be true while the timer is in the correct spot and waiting for the # key to be pressed agian

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
				if(currentKeypadValue <= 59)
					setClockStartPosition(currentKeypadValue);
				stepperInPlace = true;
				
				//dont allow the user to input any more data untill the next cycle
				timerAwaitingStart = true;
			}
	}
}