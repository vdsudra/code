#include<stdio.h>

float sum(float n,float d)
{
printf("%f\n",d);
   if(d < n)
      return (1/d)+sum(n,d+1);
   else
      return 1/d;
}



int main()
{

   printf("%f\n",sum(3.0,1.0));

}
