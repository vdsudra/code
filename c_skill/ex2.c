#include<stdlib.h>
#include<stdio.h>
int main()
{
   int i=10;
   int *p=NULL;
   int *q=NULL;

   p=(int *)malloc(10*sizeof(int));
   printf("%p\n",p);
   free(p);
   q=(int *)malloc(10*sizeof(int));
   free(p);
   printf("%p\n",p);
}
