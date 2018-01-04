#include<stdio.h>
int main(){
int volatile const a=10;
int *p = &a;
printf("Value before : %d\n",a);
*p=100;
printf("Value After : %d\n",a);
}
