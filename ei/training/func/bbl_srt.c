#include<stdio.h>

int main()
{
   int n;
   int i,k ,j ;
   int temp;

   scanf("%d",&n);
   int arr[n];
   for(i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
   for(i=0;i<n-1;i++)
   {
      for(j=0;j<n-i-1;j++)
      {
	 if(arr[j] > arr[j+1])
	 {
	    temp=arr[j];
	    arr[j]=arr[j+1];
	    arr[j+1]=temp;
	 }

/*      for(k=0;k<n;k++)
      {
	 printf("%d ",arr[k]);
      }
      printf("\n\n");
*/
      }


   }
   for(i=0;i<n;i++)
   {
      printf("%d ",arr[i]);
   }
   printf("\n");

}






