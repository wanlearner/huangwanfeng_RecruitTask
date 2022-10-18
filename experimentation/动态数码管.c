#include <REGX52.H>
typedef unsigned int u16;
typedef unsigned char u8;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
void delay_10us(u16 i){
	while(i--);
}
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
	                0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void smg_display(void){
	int b;
  for(b=0;b<8;b++){
	   switch(b){
			 case 0: LSA=1;LSB=1;LSC=1;break;
	     case 1: LSA=1;LSB=1;LSC=0;break;
	     case 2: LSA=1;LSB=0;LSC=1;break;
			 case 3: LSA=1;LSB=0;LSC=0;break;
			 case 4: LSA=0;LSB=1;LSC=1;break;
			 case 5: LSA=0;LSB=1;LSC=0;break;
			 case 6: LSA=0;LSB=0;LSC=1;break;
			 case 7: LSA=0;LSB=0;LSC=0;break;
	}
		 P0=gsmg_code[b];
	   delay_10us(10);
	   P0=0x00;
}
	}
void main()
{
	while(1){
		smg_display();
	}
}
	
	   