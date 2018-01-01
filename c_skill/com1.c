#include<stdio.h>
int fun(int *arr)
{
arr[4]=545;
}
int main()
{

   char *str="vinay";
   int arr[5]={2,4,5,7,8};
   printf("%d %d \n",sizeof(str),sizeof(*str));
fun(&arr);
   int i;
for(i=0;i<5;i++)
{
   printf("%d  ",arr[i]);

}

}
