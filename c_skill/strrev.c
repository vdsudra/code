#include<stdio.h>
char * strrev(char *str)
{
   int i=0,j=0;
   char ch;
   while(str[i])
      i++;
   str[i--]='\0';
   for(j=0; j < i; j++,i--)
   {
      ch = str[i];
      str[i] = str[j];
      str[j] = ch;
   }

   return str;
}
      


int main()
{
   int i;
   char str[20];
   gets(str);
   strrev(str);
   printf("%s\n",str);
}
   
