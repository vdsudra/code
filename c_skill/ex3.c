#include<stdio.h>

int main()
{
   int a[3][3]={1,2},{3,4},{5,6};
   int i;
   int j;
   for(i=0;i<3;i++)
   {
      for(j=0;j<3;j++)
      {
         printf("%d ",a[i][j]);
      }
   }

}
