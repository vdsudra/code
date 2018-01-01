#include<stdio.h>
int chs(int x, int y)
{
	return x^y > 0;
}

int main()
{
	int a;
	a=chs(1,-2);
	if(a)
	{
		printf("Opposite Sign\n");
	}
	else 
	{
		printf("Same Sign\n");
	}
}
