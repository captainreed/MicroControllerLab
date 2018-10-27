#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>

#define bool _Bool
void initKeypad(void);//built
void scanKeypad(void);
void findLocation(void);
char gridToChar(void);//built
void debounce(int);//built
int getRow();
int getCol();
bool poundPressed();
void displayMessage(char);//built
int getKeypadIntValue();
bool poundPressed();
//void clear();



#endif /* KEYPAD_H */








