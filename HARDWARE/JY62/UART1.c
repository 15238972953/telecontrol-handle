#include <stdio.h>
#include "misc.h"
#include "UART1.h"

char QR_code;
static unsigned char TxBuffer[256];
static unsigned char TxCounter=0;
static unsigned char count=0; 
extern void CopeSerial1Data(unsigned char ucData);
volatile int stop_flag=0;
void Initial_UART1(unsigned long baudrate)
{
    //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE); //ʹ��GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//ʹ��USART1ʱ��
 
	//����1��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_USART1); //GPIOA9����ΪUSART1
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_USART1); //GPIOA10����ΪUSART1
	
	//USART1�˿�����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; //GPIOA9��GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOB,&GPIO_InitStructure); //��ʼ��PA9��PA10

   //USART1 ��ʼ������
	USART_InitStructure.USART_BaudRate = baudrate;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(USART1, &USART_InitStructure); //��ʼ������1
	
  USART_Cmd(USART1, ENABLE);  //ʹ�ܴ���1 
	
	//USART_ClearFlag(USART1, USART_FLAG_TC);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//��������ж�

	//Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//����1�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����
}

void UART1_Put_Char(unsigned char DataToSend)
{
	TxBuffer[count++] = DataToSend;  
  USART_ITConfig(USART1, USART_IT_TXE, ENABLE);  
}

void UART1_Put_String(unsigned char *Str)
{
	while(*Str)
	{
		if(*Str=='\r')UART1_Put_Char(0x0d);
			else if(*Str=='\n')UART1_Put_Char(0x0a);
				else UART1_Put_Char(*Str);
		Str++;
	}
}

//�ض���fputc���� 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//ѭ������,ֱ���������   
    USART1->DR = (u8) ch;      
	return ch;
}

void USART1_IRQHandler(void)//���ݽ���
{
  
	if(USART_GetITStatus(USART1, USART_IT_TXE) != RESET)
  {   
    USART_SendData(USART1, TxBuffer[TxCounter++]); 
    if(TxCounter == count) 
		{
			USART_ITConfig(USART1, USART_IT_TXE, DISABLE);// ȫ���������
		}
    USART_ClearITPendingBit(USART1, USART_IT_TXE); 
  }
	else if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
  {
		stop_flag=USART_ReceiveData(USART1);
//		CopeSerial1Data((unsigned char)USART1->DR);//��������
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
  }
	USART_ClearITPendingBit(USART1,USART_IT_ORE);

}

//void USART1_IRQHandler(void)
//{
//	 char res;

//    if(USART_GetITStatus(USART1,USART_IT_RXNE))
//			{
//        res=USART_ReceiveData(USART1);
//			  QR_code=res;
//			}
//	USART_ClearITPendingBit(USART1,USART_IT_ORE);
//}

//��ö�ά������

//void USART1_IRQHandler(void)//���ݽ���
//{
//if(USART_GetITStatus(USART1, USART_IT_TXE) != RESET)
//	QR_code=USART_ReceiveData(USART1);
//}
