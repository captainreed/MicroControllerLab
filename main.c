#include "stm32l476xx.h"
#include "lcd.h"
#include "Keypad.h"
#include "PiezoBuzzer.h"
#include "ServoDriver.h"
#include "TimeHandler.h"

int main(void){
	
	// Switch system clock to HSI here
	
  LCD_Initialization();
	initKeypad();
	initBuzzer();
	initServo();
	setClockStartPosition(45);
	soundBuzzer(1);
	runServo(45);
	//initTimeHandler();
	soundBuzzer(3);
	while(1)
	{
		HandleTime();
	}
	
}
