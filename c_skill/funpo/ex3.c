#include<stdio.h>
int sum(int a, int b)
{
   return a+b;
}

int sub(int a, int b)
{
   return a-b;
}

int mul(int a, int b)
{
   return a*b;
}

int op(int (*fun)(int,int), int x ,int y)
   
{
   int ans;
   ans=fun(x,y);
   return ans;
}

int main()
{

   //int (*fun_p)(int ,int);
   //int (*op_p)((*fun),int,int);

   //op_p=op;

   int i;

   //fun_p=sum;
   i=op(sum,10,20);
   printf("%d\n",i);
   //fun_p=sub;
   i=op(sub,100,20);
   printf("%d\n",i);
   //fun_p=mul;
   i=op(mul,10,20);
   printf("%d\n",i);
}

