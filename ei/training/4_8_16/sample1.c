#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
//int i;
printf("%p\n",argv);
printf("argv=%s\n",*argv);
argv++;
printf("%p\n",argv);
printf("argv=%s\n",*argv);

return 0;


}
