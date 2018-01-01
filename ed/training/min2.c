#include<stdio.h>
int main()
{
	int n=6;
	int a[6]={5,2,4,6,3,7};
	int i=0;
	int m1,m2;
	m1=m2=1000000;
	for(i=0;i<n;i++)
	{
		if(a[i]<m1)
			m1=a[i];
	}

	for(i=0;i<n;i++)
	{
		if(a[i]<m2 && a[i] != m1 )
			m2=a[i];
	}
	printf("%d\n",m1+m2);
}
