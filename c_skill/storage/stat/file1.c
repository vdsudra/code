#include<stdio.h>
int i=20;
int main()
{
   printf("--->%s i:%d\n",__FILE__, i);
   hello();
   printf("--->%s i:%d\n",__FILE__, i);
   return 0;
}


int hello()
{

   printf("--->%s i:%d\n",__FILE__, i);
}
