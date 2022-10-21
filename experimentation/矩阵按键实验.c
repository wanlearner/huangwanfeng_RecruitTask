#include <REGX52.H>
typedef unsigned int u8;
typedef unsigned char u16;
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void delay(u8 t){
  while(t--);
}
u8 key_matrix_ranks_scan(void){
  u8 key_value=0;
	P1=0xf7;
	if(P1!=0xf7){
	 delay(1000);
		switch(P1){
		  case 0x77: key_value=1;break;
			case 0xb7: key_value=5;break;
			case 0xd7: key_value=9;break;
			case 0xe7: key_value=13;break;
		}
	}
	while(P1!=0xf7);
	
	P1=0xfb;
	if(P1!=0xfb){
	 delay(1000);
		switch(P1){
		  case 0x7b: key_value=2;break;
			case 0xbb: key_value=6;break;
			case 0xdb: key_value=10;break;
			case 0xeb: key_value=14;break;
		}
	}
	while(P1!=0xfb);
	
	P1=0xfd;
	if(P1!=0xfd){
	 delay(1000);
		switch(P1){
		  case 0x7d: key_value=3;break;
			case 0xbd: key_value=7;break;
			case 0xdd: key_value=11;break;
			case 0xed: key_value=15;break;
		}
	}
	while(P1!=0xfd);
	
	P1=0xfe;
	if(P1!=0xfe){
	 delay(1000);
		switch(P1){
		  case 0x7e: key_value=4;break;
			case 0xbe: key_value=8;break;
			case 0xde: key_value=12;break;
			case 0xee: key_value=16;break;
		}
	}
	while(P1!=0xfe);
	
	return key_value;
}
void main(){
  u8 key=0;
	while(1){
	  key=key_matrix_ranks_scan();
		if(key!=0)
			P0=gsmg_code[key-1];
	}
}