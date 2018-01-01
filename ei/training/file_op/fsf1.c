#include<stdio.h>
int main()
{
FILE *fp=NULL;
char buffer[100]={0};
char buf[100]={0};
fp=fopen("test.txt","r");
if(fp==NULL)
{
perror("Error");
return 1;
}
fscanf(fp,"%11[^\n] %[^\n]",buffer,buf);
printf("%s\t\t%s\n",buffer,buf);
}
