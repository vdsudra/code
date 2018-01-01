#include<stdio.h>
int merge(int *a, int l ,int m, int r);
int sort(int *a,int l, int r);

int main()
{
   int arr[5]={1,5,2,4,3};
   int i=0;
   int n=5;
   sort(arr,0,n-1);
   for(i=0;i<n;i++)
      printf("%d\n",arr[i]);
}

int sort(int *a,int l, int r)
{
   if(l<r)
   {
      int m=(l+r-1)/2;
      sort(a,l,m);
      sort(a,m+1,r);
      merge(a,l,m,r);
   }
}

int merge(int *a, int l ,int m, int r)
{
   int i,j,k;
   int n1=m-l+1;
   int n2=r-m;

   int L[n1];
   int R[n2];

   for(i=0;i<n1;i++)
      L[i]=a[i+l];
   
   for(i=0;i<n2;i++)
      R[i]=a[i+m+1];

   i=j=k=0;
   k=l;
   while(i<n1 && j<n2)
   {
      if(L[i]<=R[j])
      {
         a[k]=L[i];
         i++;
      }
      else
      {
         a[k]=R[j];
         j++;
      }
      k++;
   }
   if(i<n1)
   {
      a[k]=L[i];
      i++;
      k++;
   }
   if(j<n2)
   {
      a[k]=R[j];
      j++;
      k++;
   }
}

