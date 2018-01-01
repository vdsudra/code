#include<stdio.h>
int i=100;
int main(){
extern int i;
printf("%s,  %d\n",__func__,i);
myfun();
printf("%s,  %d\n",__func__,i);
}

