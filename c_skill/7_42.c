#include<stdio.h>
int main()
   {
      float a=3.14;
      char *j;
      char i;
      j=(char *)&a;
      i=a;
      printf("i=%#x j=%#x\n",i,*j);
      return 0;
   }

