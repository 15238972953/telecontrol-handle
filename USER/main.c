#include "main.h"

	u8 key=0,mode;

int main(void)																																																																																																																																																																																																
{
	//��ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ж����ȼ� ��ʼ��
	delay_init(168);		   //��ʼ����ʱ����
	LED_Init();				    //��ʼ��LED�˿�
	BEEP_Init();
	KEY_Init();
	OLED_Init();
	EC11_Init();
	POWER_Init();
	ROCKER_Init();
	NRF24L01_Init();
	TIM6_init(10-1,8400-1); //0.01s��ʱ�ж�
	TIM7_init(100-1,8400-1); //0.01s��ʱ�ж�

	//������
	while(1){
		key_value = KEY_Scan(0);
		show_voltage(1);
		show_rocker_xy(20,20,50,20);
		if(0!=key_value){
			OLED_ShowNum(80,50,key_value,2,8,1);		
		}
		OLED_Refresh();
		delay_ms(10);
		
		tmp_buf[0]=32;           //��ʾ���ݵĳ���
		tmp_buf[1]=EC11_Num1;    //��ת������1�ı���ֵ
		tmp_buf[2]=adcx1;        //ң��1����ֵ
		tmp_buf[3]=adcy1;
		tmp_buf[4]=adcx2;
		tmp_buf[5]=adcy2;
		tmp_buf[6]=key_value;   //�洢���а�����ֵ/
		NRF24L01_TxPacket(tmp_buf);
		
		
		
//		if(NRF24L01_TxPacket(tmp_buf)==TX_OK){
//			OLED_ShowNum(0,20,9,2,8,1);
//			OLED_Refresh();
//			delay_ms(10);
//		}
	}
	return 0;
}		
