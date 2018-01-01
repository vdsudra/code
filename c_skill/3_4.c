#include<stdio.h>
int main()
{  
   int i=1;
   i=i++;
   printf("I:%d\n",i);
   i=2;
   printf("++I:%d I++:%d\n",++i,i++);
   i=2;
   printf("++I:%d I++:%d\n",++i,++i);

   i=2;
   printf("++I:%d I++:%d\n",i++,i++);
   return 0;
}

