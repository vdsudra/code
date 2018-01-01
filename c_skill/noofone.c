#include<stdio.h>
int main()
{
   char n=10;
   int i=0;
   while(n>0)
   {
      n &=(n-1);
      i++;
   }
   printf("%d\n",i);
   return 0;
}

