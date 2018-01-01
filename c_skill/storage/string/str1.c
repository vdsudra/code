#include<stdio.h>

char* str(char *s, int p, int n)
{
   printf("%d %d  %s\n",p,n,s);
   sleep(1);
   if(p<n)
   {
      s[n]=s[n]+s[p];
      s[p]=s[n]-s[p];
      s[n]=s[n]-s[p];
      str(s,++p,--n);
   }
   return 0;
}


int main()
{
   char s[100]="thisismystring";
   str(s,0,13);
   printf("%s\n",s);
}


   
