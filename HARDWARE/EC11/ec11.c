#include "ec11.h"

u8 EC11_Num1 = 50;
u8 EC11_Num2 = 50;

//EC11_KEY1���º�ִ���¼�
void EC11_KEY1_click_do(){
	
}

//EC11_KEY2���º�ִ���¼�
void EC11_KEY2_click_do(){

}
 
//��ʱ��3����
void TIM3_Int_Init(u16 arr, u16 psc)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//TIM2ʱ��ʹ��    
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE); //ʹ��ָ����TIM7�ж�,��������ж�
 
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//�����ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
 
	TIM_Cmd(TIM3, ENABLE);//������ʱ��4
}

//��ʱ��4����
void TIM4_Int_Init(u16 arr, u16 psc)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//TIM2ʱ��ʹ��    
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE); //ʹ��ָ����TIM7�ж�,��������ж�
 
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//�����ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
 
	TIM_Cmd(TIM4, ENABLE);//������ʱ��4
}
 
//��ʱ��3�жϷ������		    
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)//�Ǹ����ж�
	{
		EC11_Hander1(Encoder_EC11_Scan1());
 
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //���TIM4�����жϱ�־    
	}
}

//��ʱ��4�жϷ������		    
void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)//�Ǹ����ж�
	{
		EC11_Hander2(Encoder_EC11_Scan2());

		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);  //���TIM4�����жϱ�־    
	}
}
 
//*******************************************************************/
//���ܣ���ʼ��EC11��ת��������ز���
//�βΣ�EC11��ת������������-->>  unsigned char Set_EC11_TYPE  <<--  ��0----һ��λ��Ӧһ���壻1�����0��----����λ��Ӧһ���塣
//���أ���
//��⣺��EC11��ת������������IO����IO��ģʽ���á��Լ�����صı������г�ʼ��
//*******************************************************************/
void EC11_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
 
	GPIO_SetBits(GPIOA, GPIO_Pin_12);
	GPIO_SetBits(GPIOB, GPIO_Pin_4|GPIO_Pin_5);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	GPIO_SetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13);
 
	//�����ϵ�ʱEC11��ťλ�ò�ȷ������һ�ζ�������
	EC11_A1_Last = EC11_A1;
	EC11_B1_Last = EC11_B1;
	
	EC11_A2_Last = EC11_A2;
	EC11_B2_Last = EC11_B2;
	
	TIM3_Int_Init(10-1,8399);	//��ʼ����ʱ��3 10ms�ж�
	TIM4_Int_Init(10-1,8399);	//��ʼ����ʱ��4 10ms�ж�
 
}
//*******************************************************************/
//���ܣ����ݶ�Ӧ�β�EC11_Valueʵ�ֶ�Ӧ����
//�βΣ�EC11_Value
//���أ���
//��⣺��ת�������Ĺ��ܷ�װ���������Ը����Լ����뷨�����Ӧʵ�ֵĹ���
//*******************************************************************/
void EC11_Hander1(u8 EC11_Value)
{
	if (EC11_Value == 1) //��ת
	{
		//--------��������ת��������--------//
		EC11_Num1++;
	}
	else if (EC11_Value == 2)    //��ת
	{
		//--------��������ת��������--------//
		EC11_Num1--;
	}
	else if (EC11_Value == 3)    //��ѹһ��
	{
		//--------������������ѹһ�δ���--------//
		EC11_KEY1_click_do();
	}	
}

void EC11_Hander2(u8 EC11_Value)
{
	if (EC11_Value == 1) //��ת
	{
		//--------��������ת��������--------//
		EC11_Num2++;
	}
	else if (EC11_Value == 2)    //��ת
	{
		//--------��������ת��������--------//
		EC11_Num2--;
	}
	else if (EC11_Value == 3)    //��ѹһ��
	{
		//--------������������ѹһ�δ���--------//
		EC11_KEY2_click_do();
	}
}
//*******************************************************************/
//���ܣ���EC11��ת�������Ķ������з�������������Ӧ�Ķ����������
//�βΣ���
//���أ�char AnalyzeResult = 0;Ŀǰ���á����ڸú��������˶������������ķ���ֵ�������
//��⣺��EC11��ת�������Ķ�������ģʽ�������ǵ�������˫�����ǳ������ֻ���һֱ���¡��βδ� [ char Encoder_EC11_Scan(unsigned char Set_EC11_TYPE) ] �������롣�ڱ��������޸���Ҫ�Ķ����������
//*******************************************************************/
 
//*******************************************************************/
//���ܣ�ɨ��EC11��ת�������Ķ��������������ظ�������������ʹ��
//�βΣ�EC11��ת������������-->>  unsigned char Set_EC11_TYPE  <<--  ��0----һ��λ��Ӧһ���壻1�����0��----����λ��Ӧһ����
//���أ�EC11��ת��������ɨ����-->>  char ScanResult  -->>  0���޶�����1����ת�� -1����ת��2��ֻ���°�����3�����Ű�����ת��-3�����Ű�����ת
//��⣺ֻɨ��EC11��ת��������û�ж������������ǵڼ��ΰ��°����򳤰���˫��������ֱֵ����Ϊ�βδ��� [ void Encoder_EC11_Analyze(char EC11_Value); ] ����ʹ��
//*******************************************************************/
char Encoder_EC11_Scan1(void)
{
	//���´���A��B��һ��ֵ�ı�������Ϊ��̬ȫ�ֱ����������EC11��Ӧ��IO������ʼ��
	//  static char EC11_A_Last = 0;
	//  static char EC11_B_Last = 0;
	char ScanResult = 0;    //���ر�����ɨ���������ڷ����������Ķ���
	
	//����ֵ��ȡֵ��   0���޶�����      1����ת��   2����ת��  
	//                 3��ֻ���°�����  4��˫����   5������
	//======================================================//
              
	if (EC11_A1 != EC11_A1_Last)   //��AΪʱ�ӣ�BΪ���ݡ���תʱAB���࣬��תʱABͬ��
	{
		if (EC11_A1 == 0)
		{
			if (EC11_B1 == 1)      //ֻ��Ҫ�ɼ�A�������ػ��½��ص�����һ��״̬����A�½���ʱBΪ1����ת                    
				 ScanResult = 1;     //��ת
			else                    //��ת
				 ScanResult = 2;
			}
			EC11_A1_Last = EC11_A1;   //���±�������һ��״̬�ݴ����
			EC11_B1_Last = EC11_B1;   //���±�������һ��״̬�ݴ����
	}
	
	//EC11��������
	if(0==EC11_KEY1){
		delay_ms(10);
		if(0==EC11_KEY1 && 1==EC11_KEY1_Last){
		ScanResult = 3;
		EC11_KEY1_Last = 0;
		}
	}
	
	return ScanResult;
}

char Encoder_EC11_Scan2(void)
{
	//���´���A��B��һ��ֵ�ı�������Ϊ��̬ȫ�ֱ����������EC11��Ӧ��IO������ʼ��
	//  static char EC11_A_Last = 0;
	//  static char EC11_B_Last = 0;
	char ScanResult = 0;    //���ر�����ɨ���������ڷ����������Ķ���
	
	//����ֵ��ȡֵ��   0���޶�����      1����ת��   2����ת��  
	//                 3��ֻ���°�����  4��˫����   5������
	//======================================================//
              
	if (EC11_A2 != EC11_A2_Last)   //��AΪʱ�ӣ�BΪ���ݡ���תʱAB���࣬��תʱABͬ��
	{
		if (EC11_A2 == 0)
		{
			if (EC11_B2 == 1)      //ֻ��Ҫ�ɼ�A�������ػ��½��ص�����һ��״̬����A�½���ʱBΪ1����ת                    
				 ScanResult = 1;     //��ת
			else                    //��ת
				 ScanResult = 2;
			}
			EC11_A2_Last = EC11_A2;   //���±�������һ��״̬�ݴ����
			EC11_B2_Last = EC11_B2;   //���±�������һ��״̬�ݴ����
	}
	
	//EC11��������
	if(0==EC11_KEY2){
		delay_ms(10);
		if(0==EC11_KEY2 && 1==EC11_KEY2_Last){
		ScanResult = 3;
		EC11_KEY2_Last = 0;
		}
	}
	return ScanResult;
}
 
 
 