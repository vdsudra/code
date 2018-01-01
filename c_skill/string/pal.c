#include<stdio.h>
int pal(char *s)
{
   int i=0,j=0;
   while(s[++i]);
   i--;
   for(j=0;j<i;j++,i--)
   {
      if(s[i]==s[j])
         continue;
      else
         return 0;
   }
   return 1;
}


int main()
{
   char *s ="12i321";
   int i=0;
   i=pal(s);
   if(i)
      printf("Palindrom\n");
   else
      printf("Not Palindrom\n");   
}


