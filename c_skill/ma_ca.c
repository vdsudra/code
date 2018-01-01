#include<stdio.h>
#include <stdlib.h>

int main()
{
   int *p;
   int *q;
   int i;
   p=(int *) malloc(5*sizeof(int));
   q=(int *)calloc(5,sizeof(int));

   for(i=0;i<5;i++)
   {
      printf("Malloc %d:%u\n",i,&p);
      p++;
   }

   for(i=0;i<5;i++)
   {
      printf("Calloc %d:%u\n",i,&q);
      q++;
   }

}
