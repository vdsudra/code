#include<stdio.h>
#define PRINT(fmt, arg...) {\
	printf(fmt,arg);\
	}

#define PRINT1(fmt, arg...) {\
	fprintf(0,fmt,arg);\
	}
int main(){
	PRINT("%d Hi %f\n",123,123.45); 
	PRINT1("%d Hi %f\n",123,123.45); 
	return 0;
}
