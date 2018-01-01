#include<stdio.h>
#define N 1
	int main(){
			int A[N]={30};
			unsigned long long k=0;

			int i;
			int count=0;
			for(i=0;i<N;i++)
			{
					k=k+(1<<A[i]);
					printf("K:%llu\n",k);
			}
			k=k*3;
			printf("K:%llu\n",k);
			while(k)
			{
					k = k&(k-1);
					count++;
			}
			printf("%d\n",count);
			return 0;
}
