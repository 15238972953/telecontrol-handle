#include "variable.h"


 void ALL_Init(void)
{
 	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ж����ȼ� ��ʼ��
	delay_init(168); //delay������ʼ��
	Initial_UART2(9600); //�����ǳ�ʼ��
	Initial_UART1(115200); //�����ǡ���pc�����ʼ��
	uart3_init(115200);  //����ͷ1
	uart4_init(115200);  //����ͷ2
	LED_Init();//LED��ʼ��
	IO_Init();//��翪�س�ʼ��
	motor_Init(); //���IO��ʼ��
	TIM9_PWM_AB_Init();//���AB pwm ��ʼ��
	TIM10_PWMC_Init();//���C pwm��ʼ��
	TIM11_PWMD_Init();// ���D����pwm��ʼ��
	//TIM3_Int_Init(30000-1,8400-1);
//	TIM3_Encoder_Init(65535,1-1);//������1������ʼ��
//	TIM4_Encoder_Init(65535,1-1);//������2������ʼ��
	TIM2_Init();//�����ʼ��
	KEY_Init();//���غ�����ʼ�� 
	LED_Init();//LED ������ʼ��
	BEEP_Init();//������������ʼ��
	TIM5_Sonic_Cap_Init(0XFFFFFFFF,84-1);//������ TIM5 ���벶������ʼ�� ��1M��Ƶ�ʼ���
	TIM1_Sonic_Cap_Init(0XFFFF,168-1);//������ TIM1 ���벶������ʼ��   ��1M��Ƶ�ʼ���
	Ultra_Init();  //������ TRIG������ʼ��
	//��ʱ��6������ʼ��
	TIM7_init(600-1,8400-1); //��ʱ��7������ʼ��
	TIM6_init(520-1,8400-1);//0.05s��ʱ�ж�  
	TIM13_init(600-1,8400-1);//��ʱ��13 ��ʼ��
	OLED_Init();//LED��Ļ��ʼ��
	Time8_Servo_Init();
	//TIM14_Init();
}

