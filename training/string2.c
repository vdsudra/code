#include<stdio.h>
#include <string.h>

struct sample{
char name[10];
int no;
};
void fun(struct sample s){
strcpy(s.name,"Altered..");
s.no = 100000;
printf("%s\n",__func__);
}


int main(){
struct sample s1={"Eximius..", 100};
printf("%s\n",__func__);
printf("S1: %s  %d\n",s1.name,s1.no);
fun(s1);
printf("S1: %s  %d\n",s1.name,s1.no);
}
