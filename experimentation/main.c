#include <REGX52.H>
typedef unsigned int u16;
typedef unsigned char u8;
sbit DC_Motor=P1^0;
void delay(u16 ms){
	u16 i,j;
	for(i=ms;i>0;i--)
	for(j=110;j>0;j--);
}
void main(){
	DC_Motor=1;
	delay(500);
	DC_Motor=0;
	while(1){
	}
}
