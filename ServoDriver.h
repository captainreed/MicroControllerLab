#ifndef SERVODRIVER_H
#define SERVODRIVER_H

#include <stdint.h>

#define bool _Bool

void initServo();
void setTimeAndSteps(int time, int steps);

void setClockStartPosition(int location); // rotate the servo hand to the correct spot locaiton between 0 and 59
void runServo();//rotate the servo from its initial state to the 0 state in even intervals

#endif /* __STM32L476G_DISCOVERY_LCD_H */