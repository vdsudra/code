#include<stdio.h>
#define fun(arg) do\
{\
   if(arg)\
   printf("Have fun...\n");\
}while(i--)\

int main()
{
int i=20;
fun(1);
return 0;
}
