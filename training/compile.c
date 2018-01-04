#include<stdio.h>

int main(){
int i=10;
printf("%d  %d %d\n",i++,i++,i++);	//12 11 10
printf("%d\n",i);			//13
i=10;
int n;
n = i++ * ++i ;
printf("%d  N:%d\n",i,n);
return 0;
}
