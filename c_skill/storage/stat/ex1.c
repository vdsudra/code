#include<stdio.h>
//int i=20;
static int i=30;
int fun()
{
   static int i=20;
   printf("--->%s %p i:%d\n",__func__, &i,i++);
}

int main()
{
   static int i=10;
   fun();
   printf("--->%s %p i:%d\n",__func__, &i, i++);
   fun();
   printf("--->%s %p i:%d\n",__func__, &i, i++);
   fun();

   return 0;
}

