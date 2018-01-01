#include<stdio.h>
inline void swap(int *, int*);

int main()
{
   int a[5]={3,4,1,5,2};
   int i;//,j,k;

  /* for(i=1,j=0;i<5;i++)
   {
      if(a[j] > a[i])
      {
         for(k=0;k<=j;k++)
         {
            if(a[i]>a[k])
               swap(a+i,a+k);
         }
      }
      j++;
   }*/


for( int i = 0 ;i < n ; i++ )
{
   int temp = A[ i ];    
   int j = i;
   while(j > 0  && temp < A[ j -1]) 
   {
      A[j]=A[j-1];   
      j=j - 1;

   A[j] = temp;       
   }  
}
   for(i=0;i<5;i++)
   {
      printf("%d ",a[i]);
   }
   printf("\n");
}

void swap(int *x, int *y)
{

   int z=*x;
   *x=*y;
   *y=z;
   return;
}

