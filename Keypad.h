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
void displayMessage(char);//built
int getKeypadIntValue();
//void clear();



#endif /* KEYPAD_H */








