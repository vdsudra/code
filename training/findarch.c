#include<stdio.h>

int main(){
int j=1,i=0x12345678;
int *p = &i,*q=&j;
char a=10,b=11;
char *ptr=&i;
printf("%p  %p\n",p,q);
a=(int)(p)-(int)(q);
printf("A: %d\n",a);
//printf("%d\n",(int)(p-q));
//printf("%p  %p\n",&j,&i);
//printf("%d  \n",(int)(&i-&j));
//printf("%d  \n",(int)(&i-&j));
for(j=0;j<4;j++){
	printf("Adds: %p Data:%x\n",ptr,*ptr);
	ptr++;
}

return 0;
}
