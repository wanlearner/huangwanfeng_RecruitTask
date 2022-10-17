#define LED_PORT P2  //使用宏定义P2端口
#include <REGX52.H>
sbit LED1=P2^0;
typedef unsigned int u16;
typedef unsigned char u8;
void delay_10us(u16 ten_us){
  while(ten_us--);
}
void main(){
	int i;
	while(1){
	for(i=0;i<8;i++){
		LED_PORT=~(0x01<<i);
		delay_10us(50000);
	}
}
}

