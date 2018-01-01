#include<stdio.h>
int main()
{
#ifndef N 
#define N 1
#endif
	int A[N]={-1};
	int s1,s2=0;
	int p1,p2;
	int i,j;
	if(N==1)
		return A[0]+A[0];
	s1=A[0];
	p1=0;
	s2=A[N-1]-N-1;
	p2=N-1-i;
	for(i=0,j=N-1;i<N && j>=0;i++,j--)
	{
		if(A[i]+i>s1)
		{
			s1=A[i]+i;
			p1=i;
			printf("S1:%d P1:%d\n",s1,p1);
		}
		if((A[j]-j) > s2)
		{
			s2=A[j]-j;
			p2=j;
			printf("S2:%d P2:%d\n",s2,p2);
		}
	}
	s1=A[p1]+A[p2]+p1-p2;
	printf("S1:%d\n",s1);
	s2=A[p1]+A[p2]+p2-p1;
	printf("S2:%d\n",s2);
}
