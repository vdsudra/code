#include<stdio.h>
#include"link.h"

Node *head = NULL; 

int main(){
	head = add(4,head);
	head = add(1,head);
	print(head);
	head = DelOdd(head);
	print(head);

	return 0;
}


