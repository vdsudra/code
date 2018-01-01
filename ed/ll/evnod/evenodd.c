#include<stdio.h>
#include"link.h"

Node *head = NULL; 

int main(){
	head = add(1,head);
	head = add(6,head);
	head = add(4,head);
	head = add(3,head);
	head = add(9,head);
	head = add(8,head);
	head = add(11,head);
	head = add(10,head);
	head = add(7,head);
	print(head);
	head = EvenOdd(head);
	print(head);

	return 0;
}


