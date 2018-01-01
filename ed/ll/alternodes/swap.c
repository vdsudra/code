#include<stdio.h>
#include"link.h"

Node *head = NULL; 

int main(){
	head = add(1,head);
	print(head);
	head = SwapNode(head);
	print(head);

	return 0;
}


