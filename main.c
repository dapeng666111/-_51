#include <REGX52.H>
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
	P2_0=0xfe;
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
			P2_0=0xfe<<led_num;
			
		}
		if (P3_0==0)
		{
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			if (led_num==0)
			{led_num=7;
			}
			else
			{led_num--;
			}
			P2_0=0xfe<<led_num;
			
		}
	}		
	
}
