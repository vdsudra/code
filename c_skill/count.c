#include<stdio.h>
int main()
{ 
   char i=0;
   while(printf("%d",i++))
      usleep(1000);
   return 0;
}
