#include "Device/Include/stm32f10x.h"   // Device header


void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  // 使能时钟
	
	// 定义GPIO外设参数结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      // 推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;           // 定义引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     // 速度
	GPIO_Init(GPIOA,&GPIO_InitStructure);                 // GPIOA初始化
	GPIO_SetBits(GPIOA,GPIO_Pin_1);                       // 一开始让它们先别亮
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

void LED1_ON(void)
{
    GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}

void LED2_ON(void)
{
    GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

void LED1_OFF(void)
{
    GPIO_SetBits(GPIOA,GPIO_Pin_1);
}

void LED2_OFF(void)
{
    GPIO_SetBits(GPIOA,GPIO_Pin_2);
}
