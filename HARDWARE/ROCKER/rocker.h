#ifndef ROCKER_H
#define ROCKER_H

#include "sys.h"
#include "delay.h"
#include "oled.h"

extern int adcx1,adcy1,adcx2,adcy2;

void  ROCKER_Init(void);
static u16 Get_Adc(u8 ch);
static u16 Get_Adc_Average(u8 ch,u8 times);
void Get_rocker_xy();
void show_rocker_xy(u8 x1,u8 y1,u8 x2,u8 y2);

#endif
