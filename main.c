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
	initTimeHandler();
	while(1)
	{
		HandleTime();
	}
	
}
