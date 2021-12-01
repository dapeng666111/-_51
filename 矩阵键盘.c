#include <REGX52.H>


//矩阵键盘显示，对应1-9的数字

void delay(unsigned int x)   //delay 1 ms
{	x=x*100;
	while (x--);
}
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
					#delay(2);
					#P0=0x00;
		
}



unsigned char matrix()             //矩阵键盘读取
{	unsigned char num=0;	
		P1=0xff;
		P1_3=0;
		if (P1_7==0)  {delay(20);while(P1_7==0);delay(20);num=1;}
		if (P1_6==0)  {delay(20);while(P1_6==0);delay(20);num=5;}
		if (P1_5==0)  {delay(20);while(P1_5==0);delay(20);num=9;}
		if (P1_4==0)  {delay(20);while(P1_4==0);delay(20);num=13;}
		P1=0xff;
		P1_2=0;
		if (P1_7==0)  {delay(20);while(P1_7==0);delay(20);num=2;}
		if (P1_6==0)  {delay(20);while(P1_6==0);delay(20);num=6;}
		if (P1_5==0)  {delay(20);while(P1_5==0);delay(20);num=10;}
		if (P1_4==0)  {delay(20);while(P1_4==0);delay(20);num=14;}
		P1=0xff;
		P1_1=0;
		if (P1_7==0)  {delay(20);while(P1_7==0);delay(20);num=3;}
		if (P1_6==0)  {delay(20);while(P1_6==0);delay(20);num=7;}
		if (P1_5==0)  {delay(20);while(P1_5==0);delay(20);num=11;}
		if (P1_4==0)  {delay(20);while(P1_4==0);delay(20);num=15;}
		P1=0xff;
		P1_0=0;
		if (P1_7==0)  {delay(20);while(P1_7==0);delay(20);num=4;}
		if (P1_6==0)  {delay(20);while(P1_6==0);delay(20);num=8;}
		if (P1_5==0)  {delay(20);while(P1_5==0);delay(20);num=12;}
		if (P1_4==0)  {delay(20);while(P1_4==0);delay(20);num=16;}
		
		return num;
}

void main()
{	unsigned char num=0;
	unsigned char a=0;
	while(1)
	{	num=matrix();
		if (num)
			{
			nixie(0,a);
			}
		
	}

	
}
