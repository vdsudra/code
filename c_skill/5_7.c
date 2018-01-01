#include<stdio.h>
int main()
{ 
   char *arg[]={"ab","cd","ef","gh"};
   int fun(char **);
   fun(arg);
   return 0;
}

int fun(char **p)
{
   char *t;
   t=(p+=sizeof(int))[-1];
   printf("%s\n", t);
   return 0;
}


