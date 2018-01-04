#include<stdio.h>

int main(){
int n=0x87654321;
printf("N: %x\n",n);
n=convert(n,2);
printf("N: %x\n",n);
return 0;
}

int convert(int num, int flag){
	int data[4]={0};
	if(flag == 1){	 //	Little to Big: Little (Last byte first, 1234, 4 at 100- 3 at 101- 2 at 102- 1 at 103)
		data[0]= num & 0xff;
		printf("%x\n",data[0]);
		data[1]= num >> 8 & 0xff;
		printf("%x\n",data[1]);
		data[2]= num >> 16 & 0xff;
		printf("%x\n",data[2]);
		data[3]= num >> 24 & 0xff;
		printf("%x\n",data[3]);

		return (data[3] | data[2] << 8 | data[1] << 16 | data[0] << 24);
	}
	else{
		data[0]= num & 0xff;
		data[0]=(data[0] & 0x0f) << 4  | (data[0] & 0xf0) >> 4;
		printf("%x\n",data[0]);
		data[1]= num >> 8 & 0xff;
		data[1]=(data[1] & 0x0f) << 4  | (data[1] & 0xf0) >> 4;
		printf("%x\n",data[1]);
		data[2]= num >> 16 & 0xff;
		data[2]=(data[2] & 0x0f) << 4  | (data[2] & 0xf0) >> 4;
		printf("%x\n",data[2]);
		data[3]= num >> 24 & 0xff;
		data[3]=(data[3] & 0x0f) << 4  | (data[3] & 0xf0) >> 4;
		printf("%x\n",data[3]);

		return (data[3] | data[2] << 8 | data[1] << 16 | data[0] << 24);
	}
}
