#include "lcd.h"
#include "Keypad.h"
#include "PiezoBuzzer.h"
#include "ServoDriver.h"
#include "TimeHandler.h"
#include "stm32l476xx.h"

int main(void){
	
	// Switch system clock to HSI here
	
	LCD_Initialization();
	initKeypad();
	initBuzzer();
	initServo();
	initTimeHandler();
	//soundBuzzer(3);
	LCD_DisplayString((uint8_t*)"Test");
	while(1)
	{
		//HandleTime();
		scanKeypad();
	}
	
}
