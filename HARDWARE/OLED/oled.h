#ifndef __OLED_H
#define __OLED_H 

#include "sys.h"
#include "stdlib.h"	

//OLED的分辨率
#define OLED_X 128
#define OLED_Y 64

//-----------------OLED端口定义---------------- 

#define OLED_SCL_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_15)//SCL
#define OLED_SCL_Set() GPIO_SetBits(GPIOB,GPIO_Pin_15)

#define OLED_SDA_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_14)//SDA
#define OLED_SDA_Set() GPIO_SetBits(GPIOB,GPIO_Pin_14)

#define OLED_RES_Clr() GPIO_ResetBits(GPIOF,GPIO_Pin_6)//RES
#define OLED_RES_Set() GPIO_SetBits(GPIOF,GPIO_Pin_6)

#define OLED_DC_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_13)//DC
#define OLED_DC_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_13)
 		     
#define OLED_CS_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_12)//CS
#define OLED_CS_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_12)


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
void OLED_ShowChar6x8(u8 x,u8 y,u8 chr,u8 mode);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
void OLED_Show3FNum(u8 x,u8 y,float num,u8 lenf,u8 lenb,u8 size,u8 mode);//显示 带符号 小数
void OLED_ShowIntNum(u8 x,u8 y,int32_t num,u8 len,u8 size,u8 mode);//显示 带符号数字；
u32 OLED_Pow(u8 m,u8 n);
void OLED_Init(void);

#endif

