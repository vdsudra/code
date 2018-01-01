#include<stdio.h>
#include<string.h>
void strrevr(char *str,char *tmp);
int main()
{
   char str[10]="Hello";
   char str2[10]="hi";
   char temp[10]={0};
   strrevr(str,temp);
   printf("%s\n",temp);

}

void strrevr(char *str,char *tmp)
{
   int i,j,len;
   len=strlen(str);
   for(i=0,j=len-1;j>=0;j--,i++)
   {
      tmp[i]=str[j];
   }
   tmp[i]=0;


}
