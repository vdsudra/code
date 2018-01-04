#include<stdio.h>
#define LOOP(n) {\
	int i;\
	for(i=0;i<n;i++)\
		printf("Hello %d\n",i);\
	}
int main(){
	LOOP(5);
	printf("**************\n");
	LOOP(10);
	return 0;
}
