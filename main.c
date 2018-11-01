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
//<<<<<<< HEAD
	initTimeHandler();
	//soundBuzzer(3);
	LCD_DisplayString((uint8_t*)"Test");
//=======
	//setClockStartPosition(45);
	//soundBuzzer(1);
	//runServo(45);
	//initTimeHandler();
	//soundBuzzer(3);
//>>>>>>> 4be629ff626c1b71e251d93e8ef57e82205fe34f
	while(1)
	{
		//HandleTime();
		scanKeypad();
	}
	
}
