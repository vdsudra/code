#include<stdio.h>

int main(){
int n=1234;
int tmp=0;
while(n){
tmp = (tmp*10) + (n %10);
n=n/10;
}
printf("%d\n",tmp);
return 0;
}
