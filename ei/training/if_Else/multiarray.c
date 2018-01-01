#include<stdio.h>

int fun(char **[]);
int main()
{
char *data[2][5]={{"hi","hello","how","are","you"},{"a","a","c","d","e"}};
int i=0;
/*
for(i=0;i<5;i++)
{
printf("%s\n",data[0][i]);
}*/
fun(data);
return 0;
}


int fun(char **data[5])
{
int i;
//printf("%s\n",data[7]);
for(i=0;i<5;i++)
{
printf("%s\n",data[i]);
}
data++;
for(i=0;i<5;i++)
{
printf("%s\n",data[i]);
}
}
