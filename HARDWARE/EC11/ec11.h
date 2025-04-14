#ifndef __ec11_H
#define __ec11_H
 
#include "sys.h"
#include "delay.h"
#include "oled.h"

extern u8 EC11_Num1;
extern u8 EC11_Num2;

//----------------IO�ڶ���----------------//
#define EC11_A1           PBin(4)                             //EC11��A���ţ���Ϊʱ����
#define EC11_B1           PBin(5)                           	 //EC11��B���ţ���Ϊ�ź���
#define	EC11_KEY1         PCin(13)                           	 //EC11�İ���

#define EC11_A2           PDin(12)                             //EC11��A���ţ���Ϊʱ����
#define EC11_B2           PDin(13)                           	 //EC11��B���ţ���Ϊ�ź���
#define	EC11_KEY2         PAin(12)                           	 //EC11�İ���
  
//----------------�ֲ��ļ��ڱ����б�----------------//
static char EC11_A1_Last = 0;                        //EC11��A������һ�ε�״̬
static char EC11_B1_Last = 0;                        //EC11��B������һ�ε�״̬
static char EC11_KEY1_Last=1;

static char EC11_A2_Last = 0;                        //EC11��A������һ�ε�״̬
static char EC11_B2_Last = 0;                        //EC11��B������һ�ε�״̬
static char EC11_KEY2_Last=1;
//��νһ��λ��Ӧһ���壬��ָEC11��ת������ÿת��һ��A��B�������һ�������ķ�����

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
 