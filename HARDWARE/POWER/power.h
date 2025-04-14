#ifndef POWER_H
#define POWER_H

#include "sys.h"
#include "delay.h"
#include "oled.h"
#include "kalman.h"

void  POWER_Init(void);
static u16 Get_Adc(u8 ch);
u16 Get_voltage();
void show_voltage(u8 mode);


#endif
