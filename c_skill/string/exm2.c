#include<stdio.h>
#include<stdlib.h>
int main()
{
   char *i;
   int *j;
   char str[10]="hello";
   //i=(int*)malloc(10*sizeof(int));
   //j=(int*)calloc(10,sizeof(int));
   int k;
   i=str;
   j=str;
   for(k=0;k<10;k++,i++) 
   {
   printf("i:%p\n",i);
   printf("J:%s\n",j);
   //printf("i:%p j:%p\n",i,j);

   }
}

