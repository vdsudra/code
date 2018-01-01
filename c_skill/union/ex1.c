#include<stdio.h>
#include <string.h>

int main(){
	union ex{
		int x;
		int y;
		char ch[4];
	};

	union ex u;
	u.x=1;
	strcpy(u.ch,"01");
	printf("X:%d  Y:%d  Ch:%s\n",u.x,u.y,u.ch);
	printf("Sizeof ex:%d\n",(int)sizeof(u));
	return 0;

}
