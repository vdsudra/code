#include<stdio.h>
int main(){
	//int a=10;
	int i=5;
	printf("A:%d\n",a);

	for(;i>0;i--){
		static int a=100;
		printf("A:%d\n",a);
		a++;
	}
	printf("A:%d\n",a);

}
