#ifndef SERVODRIVER_H
#define SERVODRIVER_H

#include <stdint.h>

#define bool _Bool

void initServo();
void setTimeAndSteps(int time, int steps);

#endif /* __STM32L476G_DISCOVERY_LCD_H */