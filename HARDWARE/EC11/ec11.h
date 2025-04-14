#ifndef __ec11_H
#define __ec11_H
 
#include "sys.h"
#include "delay.h"
#include "oled.h"

extern u8 EC11_Num1;
extern u8 EC11_Num2;

//----------------IO口定义----------------//
#define EC11_A1           PBin(4)                             //EC11的A引脚，视为时钟线
#define EC11_B1           PBin(5)                           	 //EC11的B引脚，视为信号线
#define	EC11_KEY1         PCin(13)                           	 //EC11的按键

#define EC11_A2           PDin(12)                             //EC11的A引脚，视为时钟线
#define EC11_B2           PDin(13)                           	 //EC11的B引脚，视为信号线
#define	EC11_KEY2         PAin(12)                           	 //EC11的按键
  
//----------------局部文件内变量列表----------------//
static char EC11_A1_Last = 0;                        //EC11的A引脚上一次的状态
static char EC11_B1_Last = 0;                        //EC11的B引脚上一次的状态
static char EC11_KEY1_Last=1;

static char EC11_A2_Last = 0;                        //EC11的A引脚上一次的状态
static char EC11_B2_Last = 0;                        //EC11的B引脚上一次的状态
static char EC11_KEY2_Last=1;
//所谓一定位对应一脉冲，是指EC11旋转编码器每转动一格，A和B都会输出一个完整的方波。

void EC11_KEY1_click_do();
void EC11_KEY2_click_do();
void TIM3_Int_Init(u16 arr, u16 psc);
void TIM4_Int_Init(u16 arr, u16 psc);
void EC11_Init(void);
void EC11_Hander1(u8 EC11_Value);
void EC11_Hander2(u8 EC11_Value);
char Encoder_EC11_Scan1(void);
char Encoder_EC11_Scan2(void);

#endif
 