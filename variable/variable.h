#ifndef __VAR_H
#define __VAR_H

#include "sys.h"
#include "delay.h"
#include "led.h"
#include "switch.h"
#include "motor.h"
#include "M_pwm.h"
#include "encode.h"
#include "servo.h"
#include "key.h"
#include "beep.h"
#include "oled.h"
#include "ult.h"
#include "timer.h"
#include "command.h"
#include "JY901.h"
#include "UART2.h"
#include <string.h>
#include <stdio.h>
#include "bsp_pid.h"
#include "filter.h"
#include "UART1.h"
#include "dictionary.h"
#include "main.h"
#include "math.h"
#include "UART3.h"
#include "UART4.h"
//#include "qr_num.h"

#define YAW (float)stcAngle.Angle[2]/32768*180
extern int PID_value;
extern int TIM3_sumcode;
extern int TIM4_sumcode;
extern EncoderStruct Encoders;
extern Encode  encode;
extern	SonicDis Sonic_Dis;
extern struct SAngle 	stcAngle;
extern int flag;
extern int Encoder_Timer3_sum;//定时器3编码器总数
extern int Encoder_Timer4_sum;//定时器4编码器总数
extern int flag_openmv;
extern int empt;
extern char QR_code;
extern int code;
//extern int code;
void ALL_Init(void);

#endif
