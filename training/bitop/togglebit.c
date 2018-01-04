#include<stdio.h>

int togglebit(int num, int pos){
	num = (1<<(pos-1 % 32)) ^ num ;
	return num;
} 

int main(){
	int num=0x34,pos=3;
	printf("%x\n", num);
	num = togglebit(num, pos);
	printf("%x\n", num);
	return 0;
}


