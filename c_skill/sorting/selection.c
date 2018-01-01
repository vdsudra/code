#include<stdio.h>
int main()
{
   int n=10;
   int a[10]={1,6,7,2,5,3,8,9,4,10};
   int i,j;
   for(i=0;i<n-1;i++)
   {
      for(j=i+1;j<n;j++)
      {
         if(a[i]>a[j])
         {
            a[i]=a[i]+a[j];
            a[j]=a[i]-a[j];
            a[i]=a[i]-a[j];
         }
      }
   }
   for(i=0;i<n;i++)
      printf("%d\n",a[i]);
}
