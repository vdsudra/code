#include<stdio.h>
int i;
static int hello()
{
   printf("%s i:%d\n",__FILE__, i);
   i=200;
   printf("%s i:%d\n",__FILE__, i);
   return 0;
}

