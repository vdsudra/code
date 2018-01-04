#include<stdio.h>

int setbit(int num, int pos){
	num = (1<<(pos-1 % 32)) | num ;
	return num;
} 

int main(){
	int num=0x34,pos=1;
	printf("%x\n", num);
	num = setbit(num, pos);
	printf("%x\n", num);
	return 0;
}


