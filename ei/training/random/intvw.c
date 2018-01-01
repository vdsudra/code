#include<stdio.h>
extern int n=0;
int main()
{
   int stack[5]={1,2,3,4,5};
   int i;

   *(stack+2)=20;
   for(i=0;i<n;i++)
   {
      printf("%d  ",*(stack+i));
      //printf("%d  ",stack[i]);
   }
printf("\n");
}

