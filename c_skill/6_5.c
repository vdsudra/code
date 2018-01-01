#include<stdio.h>
#define cub(x) (x*x*x)
int main()
{
   int i=3;
   printf("%d\n",cub(i++));
   return 0;
}

