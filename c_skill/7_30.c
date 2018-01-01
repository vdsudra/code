#include<stdio.h>
int main()
{
   int x=10,*y,*z;
   y=z=&x;
   printf("%p %p %p\n",(void *)&x,(void *)&y,(void *)&z);
   printf("%u %u %u\n",&x,&y,&z);
}
