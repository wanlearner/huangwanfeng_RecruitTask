#include <REGX52.H>
sbit K1=P3^1;
sbit K2=P3^2;
sbit K3=P3^3;
sbit K4=P3^4;
sbit LED1=P2^0;
void delay_1ms(unsigned int time){
   while(time--);
}
int key_scan(unsigned int mode){
  static key=1;
	if(mode==1) key=1;
	if(key==1&&(K1==0||K2==0||K3==0||K4==0)){
		delay_1ms(1000);
		key=0;
	  if(K1==0) return 1; 
	  else if(K2==0) return 2;
		else if(K3==0) return 3;
		else if(K4==0) return 4;
	 }
	 else if(K1==1&&K2==1&&K3==1&&K4==1) return 0;
}
void main(){
  unsigned int key=0;
	while(1){
	key=key_scan(1);
	if(key==1) 
		LED1=!LED1;
}
}