#include<stdio.h>
#include <string.h>
void fun(char *str){

printf("%s\n",__func__);
printf("%p : %s\n",&str,str);
strcpy(str,"Altered in fun()");
}

void myfun(char str[100]){

printf("%s\n",__func__);
printf("%p : %s\n",&str,str);
strcpy(str,"Altered in myfun()");
}

int main(){
char s[100]="Simple String..";
printf("%s\n",__func__);
printf("%p : %s\n",&s,s);
fun(s);
myfun(s);
printf("%s\n",__func__);
char *t="Hello";
char *p=s;

*p=*t;

printf("%p : %s\n",&s,s);
}
