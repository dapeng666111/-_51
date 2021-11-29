#include <REGX52.H>
#include "delay.h"


void nixie(unsigned char led_locatin,num)
{unsigned char a[]={0x3f,0x06,0x5b,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

	//数码管位置
	switch (led_locatin) 
				{	case 7:P2_4=0;P2_3=0;P2_2=0;break;
					case 6:P2_4=0;P2_3=0;P2_2=1;break;
					case 5:P2_4=0;P2_3=1;P2_2=0;break;
					case 4:P2_4=0;P2_3=1;P2_2=1;break;
					case 3:P2_4=1;P2_3=0;P2_2=0;break;
					case 2:P2_4=1;P2_3=0;P2_2=1;break;
					case 1:P2_4=1;P2_3=1;P2_2=0;break;
					case 0:P2_4=1;P2_3=1;P2_2=1;break;
				}
	//数字显示
					P0=a[num];
					delay(2);
					P0=0x00;
		
}
void main()
{
	while(1)
		{
			nixie(1,1);
			nixie(2,2);
		}
}
