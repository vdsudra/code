#include<stdio.h>
#include<string.h>
int main()
{
   char arr[5][10]={0};
   char tmp[10]={0};
   int i=0;
   int j=0;
   int res=0;
   for(i=0;i<5;i++)
   {
      scanf("%s",arr[i]);
   }


   for(i=0;i<5;i++)
   {
      for(j=i+1;j<5;j++)
      {
         if((res=strcasecmp(arr[i],arr[j]))>0)
         {
            strcpy(tmp,arr[i]);
            strcpy(arr[i],arr[j]);
            strcpy(arr[j],tmp);
         }
      }
   }

   printf("\n\n");
   for(i=0;i<5;i++)
   {
      printf("%s\n",arr[i]);
   }
}

