#include<stdio.h>

 int solution(int N)
{
    int min=0,max=0;

    while(N>0)
    {
       if((N&1) == 1)
       {
          //max=(min>max)?min:max;
          if(min>max)
             max=min;

          min=0;
          N=N>>1;
       }
       else
       {
          min++;
          N=N>>1;
       }
       printf("N:%d\n",N);
    }
    return max;
 }

int main()
{
printf("%d\n",solution(33));
}
