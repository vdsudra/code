#include<stdio.h>

int resetbit(int num, int pos){
	num = ~(1<<(pos-1 % 32)) & num ;
	return num;
} 

int main(){
	int num=0x34,pos=6;
	printf("%x\n", num);
	num = resetbit(num, pos);
	printf("%x\n", num);
	return 0;
}


