#include<stdio.h>
int main()
{
	int a[10]={5,9,4,7,15,3,8,11,2,17};
	int i,max,min;
	max=min=a[0];
	for(i=1;i<10;i++)
	{
		if(a[i] < min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	printf("Min:%d Max:%d\n",min,max);
}

