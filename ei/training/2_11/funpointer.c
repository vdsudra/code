#include<stdio.h>
void my_fun(int);
int main()
{
FILE *fp=NULL;
void (*ptr)(int);
ptr=&my_fun;
ptr(10);
//fclose(fp);

}

void my_fun(int a)
{
printf("--->>%d<<--\n",a);
}
