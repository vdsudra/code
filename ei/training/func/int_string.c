#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
long a;
scanf("%ld",&a);
long temp=0;
long div=0;
int i=0;
int j;
char str[1024]={0};
char str2[1024]={0};
while((a/10)!=0)
{
temp=a%10;
str[i]=temp+48;
i++;
a=a/10;
}
if((a%10) !=0)
{
str[i]=(a%10)+48;
}
strcpy(str2,str);
for(j=0;i>=0;i--,j++)
{
str[j]=str2[i];
}
printf("%s  %d\n",str,(int)strlen(str));

}
