#include<stdio.h>
int sum(int a, int b)
{
   return a+b;
}

char *fun()
{
   char *s="Hello";
   return s;
}
int main()
{

   int (*ptr)(int ,int);
   char* (*p)();

   int i;
   char *str;

   ptr=sum;
   p=fun;
   i=ptr(10,20);
   str=p();
   printf("%d\n",i);
   printf("%s\n",str);
}

