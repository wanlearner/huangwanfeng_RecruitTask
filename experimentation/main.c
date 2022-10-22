#include <REGX52.H>
typedef unsigned int u8;
typedef unsigned char u16;
sbit SRCLK=P3^6;
sbit PCLK=P3^5;
sbit SER=P3^4;
void delay(u8 t){
  while(t--);
}
void hc595_write_date(u8 dat){
  u8 i=0;
	for(i=0;i<=8;i++){
	  SER=dat>>7;
		dat<<=1;
		SRCLK=1;
		delay(1);
	}
	PCLK=0;
	delay(1);
	PCLK=1;
}
void main(){
  u8 i=0;
	P0=0x7f;
	while(1){
	  hc595_write_date(0x80);
	}
}