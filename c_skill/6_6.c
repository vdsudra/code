#include<stdio.h>
#define swap(a,b,c) c t;t=a,a=b,b=t;
int main()
{
   int x=10,y=20;
   swap(x,y,int);
   printf("%d %d\n",x,y);
   return 0;
}
