#include<stdio.h>
int main()
{
   int n=9;
   int first=0,last=0,mid=0;
   int i=0,j=0;
   int tmp=n;
   while((tmp/10) > 0)
   {
      i++;
      tmp/=10;
   }
   
   tmp=1;
   while(i--)
      tmp*=10;
   first=n/tmp;
   last=n%10;
   printf("First:%d  Last:%d\n",first,last);
   printf("%d\n",n);
   n=((last*tmp)+(n-(first*tmp)-last)) +first;
   printf("%d\n",n);
   return 0;
}



