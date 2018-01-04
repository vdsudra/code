#include<stdio.h>
//register int a=10;  error
register int *add(void);
int main(){
//int *p = &a;
printf("Value before : %d\n",a);
//*p=100;
printf("Value After : %d\n",a);
}
