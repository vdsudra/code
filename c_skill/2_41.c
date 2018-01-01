#include<stdio.h>
int main()
{
   int x=3;
   float y =3.0;
   if(y == x)
      printf("X and Y are equal\n");
   else
      printf("X and Y are not equal\n");
   x=y;
   printf("X:%d\n",x);

   return 0;
}

