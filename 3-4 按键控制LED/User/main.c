#include "stm32f10x.h"   // Device header
#include "Delay.h"
#include "LED.h"
#include "Button.h"

int main(void)
{
	Button_Init();
	LED_Init();
	while(1)
	{
		if(Button_get()==1)
		{
			LED2_ON();
			Delay_s(1);
			LED2_OFF();
			if(Button_get()==2)
				LED1_ON();
			Delay_s(1);
		}
		LED1_OFF();
	}
}
	
	
	
	
	
//	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      // 推挽输出
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;             // 定义引脚
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     // 速度
//	
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);  // 使能时钟
//	GPIO_Init(GPIOA,&GPIO_InitStructure);                 // GPIO初始化
//	
//	// GPIO_SetBits(GPIOC,GPIO_Pin_0);                   // 设置高电平      
//	// GPIO_ResetBits(GPIOC,GPIO_Pin_0);                 // 设置低电平
//	while(1)
//	{
//		GPIO_SetBits(GPIOA,GPIO_Pin_0);          // 设置高电平  
//		Delay_ms(500);
//		GPIO_ResetBits(GPIOA,GPIO_Pin_0);        // 设置低电平
//		Delay_ms(500);
//	}


