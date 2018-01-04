#include<stdio.h>

#define PRINTMSG(a,b) \
	printf(#a" %d  %d\n",a,b);

#define PRINTMSG1(a,b) \
	printf(" %d  n",a##b);

int main(){
PRINTMSG(1,2);
PRINTMSG1(1,2);

return 0;
}
