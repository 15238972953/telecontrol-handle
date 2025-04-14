#ifndef Key_H
#define Key_H

#include "sys.h"
#include "delay.h"

extern u8 key_value;

#define KEY1 		PEin(0)   	
#define KEY2 		PEin(1)		
#define KEY3		PEin(2)		
#define KEY4	  PEin(3)	
#define KEY5 		PEin(4)   	
#define KEY6 		PEin(5)		
#define KEY7		PEin(6)		
#define KEY8	  PCin(0)	
#define KEY9 		PAin(9)   	
#define KEY10 	PCin(1)		
#define KEY11		PEin(10)		
#define KEY12	  PEin(11)

void KEY_Init(void);
u8 KEY_Scan(u8 mode);
#endif
