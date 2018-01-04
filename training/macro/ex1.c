#include<stdio.h>
#define SWAP(a,b)({a^=b;b^=a;a^=b;})
int main(){
int x=10,y=20;
printf("X:%d  Y:%d\n",x,y);
SWAP(x,y);
printf("X:%d  Y:%d\n",x,y);

return 0;
}
