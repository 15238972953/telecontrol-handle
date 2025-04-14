#include "main.h"

	u8 key=0,mode;

int main(void)																																																																																																																																																																																																
{
	//初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断优先级 初始化
	delay_init(168);		   //初始化延时函数
	LED_Init();				    //初始化LED端口
	BEEP_Init();
	KEY_Init();
	OLED_Init();
	EC11_Init();
	POWER_Init();
	ROCKER_Init();
	NRF24L01_Init();
	TIM6_init(10-1,8400-1); //0.01s定时中断
	TIM7_init(100-1,8400-1); //0.01s定时中断

	//主程序
	while(1){
		key_value = KEY_Scan(0);
		show_voltage(1);
		show_rocker_xy(20,20,50,20);
		if(0!=key_value){
			OLED_ShowNum(80,50,key_value,2,8,1);		
		}
		OLED_Refresh();
		delay_ms(10);
		
		tmp_buf[0]=32;           //表示数据的长度
		tmp_buf[1]=EC11_Num1;    //旋转编码器1的编码值
		tmp_buf[2]=adcx1;        //遥杆1的数值
		tmp_buf[3]=adcy1;
		tmp_buf[4]=adcx2;
		tmp_buf[5]=adcy2;
		tmp_buf[6]=key_value;   //存储所有按键的值/
		NRF24L01_TxPacket(tmp_buf);
		
		
		
//		if(NRF24L01_TxPacket(tmp_buf)==TX_OK){
//			OLED_ShowNum(0,20,9,2,8,1);
//			OLED_Refresh();
//			delay_ms(10);
//		}
	}
	return 0;
}		
