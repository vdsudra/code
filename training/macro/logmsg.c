#include<stdio.h>

#define LOG(fmt, arg...) {\
	fprintf(stdout,fmt,arg);\
	}
int main(){
	LOG("%d Hi %f\n",123,123.45); 
	return 0;
}
