#include<stdio.h>
int solution(int N) {
	int i;
	if(N == 0 || N == 1)
		return 0;
	if(i=sol(2,N,N))
	{

		//printf("Value:%d\n",i);
		return i;
	}
	return -1;
}

int sol(int l, int r, int n)
{
	//sleep(1);

	//printf("%d\n", __LINE__);
	int a;
	int m= (l+r)/2;

	//printf("L:%d  R:%d  M:%d N:%d\n",l,r,m,n);
	if(l==r)
	{
		if(find(l) && find(n-l)){
			//printf("Returned Value :%d\n",l);
			return l;
		}
	}
	else
	{

	if(a=sol(l,m,n))
		return a;

	if(a=sol(m+1,r,n))
		return a;
}
	return 0;
}

int find(int n){
//printf("To Find %d\n", n);
	if(n & (n>>1))
		return 0;

//printf("Succ %d\n", n);
return 1;
}
int main(){
	int y;
	scanf("%d",&y);
	printf("Solution:%d\n",solution(y));
}
