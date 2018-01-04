#include<stdio.h>

unsigned int rotateright(unsigned int num, int pos){
	unsigned int n=0, i;
	pos = pos % 32;
	for(i=0;i<pos;i++)
		n=(n<<1)|1;
	n &= num;
	n=n<<(32-pos);
	num = n | (num >> (32-pos)) ;
	return num;
} 

int main(){
	unsigned int num=0xc0000000,pos=2;
	printf("%x\n", num);
	num = rotateright(num, pos);
	printf("%x\n", num);
	return 0;
}


