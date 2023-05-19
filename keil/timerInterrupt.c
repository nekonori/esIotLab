#include<reg51.h>
sbit led = P1^0;
sbit externalInterrupt0 = IE^0;
void delay();
void main()
{ unsigned int i;
	P1 = 0;
 while(externalInterrupt0!=0)
 { led=~led;
 for(i=0;i<1000;i++)
 delay();
 }
}
void delay()
{ TMOD = 0x02;
 TH0= 0xA2;
 TR0 = 1;
 while(TF0 == 0);
 TR0 = 0;
 TF0 = 0;
}