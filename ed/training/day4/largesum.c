#include<stdio.h>

int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int x,y;
	int i=2;
	x=a[0];
	y=a[1];
	if(x>y)
	{
		x+=y;
		y=x-y;
		x=x-y;
	}
	for(i=2;i<10;i++)
	{
		if(a[i] > y)
		{
			x=y;
			y=a[i];
		}
		else if(a[i]>x)
		{
			x=a[i];
		}
	}
	printf("L:%d\n",x+y);
}
