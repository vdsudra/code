#include<stdio.h>
#define j(s1,s2) printf("%s=%s, %s=%s\n",#s1,s1,#s2,s2)
int main()
{
   char *str1="Vinay";
   char *str2="Sudra";
   j(str1,str2);
   return 0;
}
