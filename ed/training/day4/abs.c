#include<stdio.h>

int main()
{
	int mask=0;
	int x=-89;
	printf("%d\n",x);
	mask=x>>31;
	x=(x+mask)^mask;
	printf("%d\n",x);

}

