#include<stdio.h>
static int i=20;
int main()
   {
      static int i=10;
      printf("i:%d %p\n",i,&i);
      hello();
      printf("i:%d %p\n",i,&i);
      return 0;
   }

void hello()
   {
    //static int i=10;
      printf("i:%d %p\n",i,&i);
      i++;
      return;
   }
