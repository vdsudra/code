#include<stdio.h>
#include<string.h>
int AtoI(char *str)
{
   int res;
   int i=0;
   int sign=1;
   if(*str == '-')
   {
      sign=-1;
      str++;
   }

   int j=strlen(str);
   for(i=0;i<j;i++)
   {
      if(str[i] >= 48 && str[i] <= 57)
         continue;
      return 0; 
   }

   while(*str)
   {
      res = res*10 + (*str - '0');
      str++;
   }

   return res*sign;
}

int main()
{
char *str="5533355";
printf("%d\n",AtoI(str));
return 0;
}
