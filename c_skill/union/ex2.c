#include<stdio.h>
#include <string.h>

int main(){
	struct ex{
		int x;
		int y;
		char ch[4];
	};

	volatile struct ex e;
	return 0;

}
