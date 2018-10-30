#include "TimeHandler.h"
#include "Keypad.h"
#include "ServoDriver.h"
#include "PiezoBuzzer.h"

int keypadValue;
bool poundWasPressed;
bool stepperInPlace;
bool clockWound; //this flag will be true while the timer is in the correct spot and waiting for the # key to be pressed agian

bool timerRunning;
void initTimeHandler()
{
timerRunning = false;
keypadValue = 0;
poundWasPressed = false;
stepperInPlace = false;
clockWound = false; //this flag will be true while the timer is in the correct spot and waiting for the # key to be pressed agian
}

void HandleTime()
{
	//if the timer is not running allow the user to input a number from 1 to 59
//after pound has been pressed rotate the clock to the indicated position
//wait for pound to be pressed again
//while the timer is running do not accept new input from the user
//when the time has expired sound the buzzer for 1 second	
	if(!clockWound)
	{
		scanKeypad();
		poundWasPressed = poundPressed();
		keypadValue = getKeypadIntValue();
			if(poundWasPressed)
			{
				//send the stepper to the right position
				if(keypadValue <= 59)
					setClockStartPosition(keypadValue);
				//dont allow the user to input any more data untill the next cycle
				clockWound = true;
				poundWasPressed = false;
			}
	}
	else
	{
		scanKeypad();
		poundWasPressed = poundPressed();
		if(poundWasPressed)
		{
			runServo(keypadValue); //the system will rotate
			soundBuzzer(1); //sound the buzzer for 1 second
		}
		clockWound = false;
		poundWasPressed = false;
	}
}