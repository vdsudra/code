#include<stdio.h>
int solution(int A[], int N) 
{
	int p1,p2,p3;
	p1=p2=p3=1;
	int i;
	int dif=0;
	for(i=1;i<N-1;i++)
	{
		if(A[i] > dif)
			dif=A[i];
		if( A[i]< A[p1] )
		{
			p3=p2;
			p2=p1;
			p1=i;
			//printf("m1:%d p1:%d, m2:%d p2:%d,m3:%d p3:%d\n",m1,p1,m2,p2,m3,p3);
		}
		else if( A[i]< A[p2] )
		{
			p3=p2;
			p2=i;
			//printf("m2:%d p2:%d,m3:%d p3:%d\n",m2,p2,m3,p3);
		}
		else if( A[i]< A[p3] )
		{
			p3=i;
			//printf("m2:%d p2:%d,m3:%d p3:%d\n",m2,p2,m3,p3);
		}
	}
	dif=dif+dif;
	//printf("m1:%d p1:%d, m2:%d p2:%d, m3:%d,p3:%d\n",m1,p1,m2,p2,m3,p3);
	for(i=1;i<N-1;i++)
	{
		if((A[p1]+A[i]< dif) && ( ( p1-i > 1) || (i-p1 >1) ))
		{
			dif=A[p1]+A[i];
			//printf("diff:%d p1 i:%d\n",dif,i);
		}
		else if((A[p2]+A[i]< dif) && ( ( p2-i > 1) || (i-p2 >1) ))
		{
			dif=A[p2]+A[i];
			//printf("diff:%d p2 i:%d\n",dif,i);
		}
		else if((A[p3]+A[i]< dif) && ( ( p3-i > 1) || (i-p3 >1) ))
		{
			dif=A[p3]+A[i];
			//printf("diff:%d p3 i:%d\n",dif,i);
		}
	}
	return dif;
}
int main()
{
	int a[5]={1000000000, 123456789, 1000000000,1000000000,1000000009,};
	printf("%d\n",solution(a,5));
}
