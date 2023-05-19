#include<reg51.h>
void main()
{ TMOD = 0x20;
 TH1 = 0xFD; // Baud rate = 9600
	TL1 = 0xFD;
 SCON = 0x40;
 TR1 = 1;
 while(1)
 { SBUF='A';
 while(TI==0);
 TI=0;
 }
}