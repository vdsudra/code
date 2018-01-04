#include<stdio.h>
#define cat(x,y) x##y 
int main(){
//cat(cat(1,2),3);
printf("Output :%d", cat(2,3));
printf("Output2 :%d", cat(1,cat(2,3)));
}
