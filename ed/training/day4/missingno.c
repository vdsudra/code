#include<stdio.h>
int main()
{
	int a[9]={1,2,3,4,5,7,8,9,10};
	int i;
	for(i=0;i<9;i++)
	{
		if((a[i]^(i+1)))
		{
			printf("%d\n",i+1);
			break;

		}
	}
}
