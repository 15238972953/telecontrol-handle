#include "variable.h"


 void ALL_Init(void)
{
 	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断优先级 初始化
	delay_init(168); //delay函数初始化
	Initial_UART2(9600); //陀螺仪初始化
	Initial_UART1(115200); //陀螺仪——pc传输初始化
	uart3_init(115200);  //摄像头1
	uart4_init(115200);  //摄像头2
	LED_Init();//LED初始化
	IO_Init();//光电开关初始化
	motor_Init(); //电机IO初始化
	TIM9_PWM_AB_Init();//电机AB pwm 初始化
	TIM10_PWMC_Init();//电机C pwm初始化
	TIM11_PWMD_Init();// 电机D——pwm初始化
	//TIM3_Int_Init(30000-1,8400-1);
//	TIM3_Encoder_Init(65535,1-1);//编码器1函数初始化
//	TIM4_Encoder_Init(65535,1-1);//编码器2函数初始化
	TIM2_Init();//舵机初始化
	KEY_Init();//开关函数初始化 
	LED_Init();//LED 函数初始化
	BEEP_Init();//蜂鸣器函数初始化
	TIM5_Sonic_Cap_Init(0XFFFFFFFF,84-1);//超声波 TIM5 输入捕获函数初始化 以1M的频率计数
	TIM1_Sonic_Cap_Init(0XFFFF,168-1);//超声波 TIM1 输入捕获函数初始化   以1M的频率计数
	Ultra_Init();  //超声波 TRIG函数初始化
	//定时器6函数初始化
	TIM7_init(600-1,8400-1); //定时器7函数初始化
	TIM6_init(520-1,8400-1);//0.05s定时中断  
	TIM13_init(600-1,8400-1);//定时器13 初始化
	OLED_Init();//LED屏幕初始化
	Time8_Servo_Init();
	//TIM14_Init();
}

