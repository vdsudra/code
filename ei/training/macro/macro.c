#include<stdio.h>
#define MUL(a,b) {printf("****\t%d\t****\n",a*b);\
printf("****\t%d\t****\n",a+b);\
printf("****\t%d\t****\n",a-b);\
printf("++++%s++ %s+++++\n",#a,#b); }


int main()
{
int i;
MUL(10,10);
printf("Ans:=%d\n",i);
printf("%s\n",__FILE__);
printf("%s",__FUNCTION__);
}
