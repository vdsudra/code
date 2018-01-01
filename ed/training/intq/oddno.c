#include<stdio.h>
int main()
{

	int arr[10]={1,7,9,3,1,1,2,3,2,4};
	int res=0;

	int i;
	for(i=0;i<10;i++)
	{
		res=res ^ arr[i];
	}
	printf("%d\n",res);
}
