#include<stdio.h>
#include<string.h>

char *fun(char *s);
int main()
{
   char *str="hi";
   printf("%s\n",str);
   //str=fun(str);
   fun(str);

   printf("%s\n",str);
   return 0;
}

char *fun(char *s)
{
   char *s2;
   s2="Vinay";
   printf("%s\n",s);
   s=s2;
   printf("%s\n",s);
   strcpy(s,"Hello");
   return s2;
}

