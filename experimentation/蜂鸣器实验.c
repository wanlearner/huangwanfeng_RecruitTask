#include <REGX52.H>
typedef unsigned int u16;//?ض???
typedef unsigned char u8;
sbit BEEP=P2^5;
void delay_10us(u16 x){
	while(x--);
}
void main(){
	int i;
	i=10;
	while(i--){
		BEEP=!BEEP;
		delay_10us(100);
	}
	i=0;
	BEEP=0;
}
		
