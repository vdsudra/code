#include<stdio.h>
int main()
{
   int ary[5],i=2;
   while(i<5)
      ary[i]=i++;
   for(i=0;i<5;i++)
      printf("%d  ",ary[i]);
   printf("\n");
   return 0;
}

