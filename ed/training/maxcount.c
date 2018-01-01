#include<stdio.h>
#include<string.h>
void fun(int *,int, int );

int main()
{
int a[13]={3,4,4,6,1,4,4,6,1,4,2,2,6};
fun(a,5,13);

}
void fun(int *A,int N,int M)
{
	int *a=(int*)calloc(N,sizeof(int));
	int i,j;
	int max=0;
	int sum=0;
	for(i=0;i<M;i++)
	{
		if(A[i] == N+1)
		{
			sum=max;
			printf("***** START\n");
			for(j=0;j<N;j++)
			{
				printf("%d ",a[j]);
			}
			printf("\n");
			memset(a,0,N*sizeof(int));
			//sum=max;   
			printf("***** MEMSET START\n");
			for(j=0;j<N;j++)
			{
				printf("%d ",a[j]);
			}
			printf("\n");
		}
		else
		{
			a[A[i]-1]++;
			if(a[A[i]-1]+ sum> max)
				max=a[A[i]-1]+sum;
			printf("A[%d]:%d a[%d]:%d \n",i,A[i],A[i]-1,a[A[i]-1]);
		}
	}
	printf("\n");
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]+sum);
	}
	printf("\n");

}
