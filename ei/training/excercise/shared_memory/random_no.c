#include<stdlib.h>
#include<stdio.h>

int main()
{
int i,n=5;
srand((unsigned) n);
for(i=0;i<n;i++)
{
printf("%d\n",rand());
}

}
