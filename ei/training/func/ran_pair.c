#include<string.h>
#include<stdio.h>
long int fact(long int z);

int main()
{
   int n;
   int p;
   scanf("%d %d",&n,&p);
   int ncr;
   int i,j;
   ncr = fact(n) / (fact(p) * fact(n - p)); 
   int pair_arry[ncr][p];
   int pair[p];
   memset(&pair_arry,0,sizeof(pair_arry));
   printf("%d\n",ncr);
   for(i=1,j=0;i<=p;i++,j++)
   {
      pair[j]=i;
   }
   for(i=0;i<ncr;i++)
   {
      for(j=0;j<p;j++)
      {
	 pair_arry[i][j]=pair[j];
      }
/*
      for(j=0;j<p;j++)
      {
	 printf("%d",pair_arry[i][j]);
      }
      printf("\n");
*/
      pair[p-1]++;
      if(pair[p-1]>n)
      {
	 roll_over(&pair,p,n);
      }
   }

   for(i=0;i<ncr;i++)
   {
      printf("%d: ",i);
      for(j=0;j<p;j++)
      {
	 printf("[%d]",pair_arry[i][j]);
      }
      printf("\n");
   }

}
int roll_over(int *pair,int p,int n)
{
   int i,j;
   int flag=1;
   do
   {
      for(i=0;i<p;i++)
      {
	 if(pair[i] > n)
	 {
	    if(i==0)
	    {
	      return 0;
	    }
	    j=i-1;
	    pair[j]++;
	    for(;j<p;j++)
	    {
	       pair[j+1]=pair[j]+1;
	    }
	    break;
	 }
      }
      if(i==p)
      {
	 break;
      }
   } while(1);
}

long int fact(long int n)
{
   if (n >= 1)
      return n*fact(n-1);
   else
      return 1;
}

