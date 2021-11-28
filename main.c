#include <REGX52.H>
//灯来回移动

void Delay1ms(int t)		//@12.000MHz
{
	unsigned char i, j;
	while(t)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
			t--;
	}
}
void main()
{int led_num=0;
	P2=0xfe;
	while(1)
	{		
		if (P3_1==0)
		{
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			led_num++;
			if (led_num>7)
			{led_num=0;
			} 
			P2=~(0x01<<led_num);
			
		}
		if (P3_0==0)
		{
			Delay1ms(20);
			while(P3_0==0);
			Delay1ms(20);
			if (led_num==0)
			{led_num=7;
			}
			else
			{led_num--;
			}
			P2=~(0x01<<led_num);
			
		}
	}		
	
}



//#include <REGX52.H>
//#include "delay.h"

//控制灯的循环
//void main ()
//{		unsigned char num=0;
//		P2=~(0x01);
//	while(1)
//	{	

//		delay(5000);
//		num++;
//		if (num==7)
//		{num=0;}
//		P2=~(0x01<<num);

//		
//		
//	}
//}


