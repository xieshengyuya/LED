#include "Device/Include/stm32f10x.h"   // Device header
#include "Delay.h"

void Button_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  // 使能时钟
	
	// 定义GPIO外设参数结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         // 上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_11;           // 定义引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     // 速度
	GPIO_Init(GPIOB,&GPIO_InitStructure);                 // GPIOA初始化
}

//返回值可以是 0:无按键  1:按了B1  2:按了B11
uint8_t Button_get(void)
{
	uint8_t num = 0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
	{
		num = 1;
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
	{
		num = 2;
	}
	return num;
}