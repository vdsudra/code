#include<stdio.h>
int main()
{
   int fun();
   printf("In%s\n",__func__);
   fun();
   printf("Return from fun()\n");
   return 0;
}
int fun()
{
   printf("In%s\n",__func__);
   exit(0);
}

