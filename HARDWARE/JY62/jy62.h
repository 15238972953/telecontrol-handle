#ifndef JY62_H
#define JY62_H

#include "sys.h"
#include <stdio.h>
#include "misc.h"
#include "oled.h"


void MPU_UART1_init(unsigned long baudrate);
void UART1_Put_Char(unsigned char DataToSend);
unsigned char UART1_Get_Char(void);
void UART1_Put_String(unsigned char *Str);
void Data_process(unsigned char data);
void show_angle();
extern float roll,pitch,yaw;

#endif
