#include<stdio.h>
#include<string.h>

float atof(char *str);
float atof(char *str)
{

   int sign=1.0;
   float pow=1.0, val=0.0;

   int i=0,j=0;
   if(*str == '-')
   {
      sign=-1.0;
      str++;
   }

   for(i=0;i<j;i++)
   {
      if((str[i] >= 48 && str[i] <= 57) || str[i] == 46)
         continue;
      return 0; 
   }

   while(*str)
   {
      if(*str == '.')
      {
         str++;
         break;
      }

      val = val*10 +(*str++ - '0');
   }

   while(*str)
   {
      val = val*10.0 +(*str++ - '0');
      pow = pow*10.0 ;
      printf("%f1\n",pow);
   }

   printf("\nval:%f  po:%f\n",val ,pow);

   return sign * (val/pow);
}



int main()
{
   char str[100]="123.123";
   printf("\n%f\n",atof(str));
}



