#include<stdio.h>
void myfun(){
extern int i;
printf("%s,  %d\n",__func__,i);
i=99;
printf("%s,  %d\n",__func__,i);
}


