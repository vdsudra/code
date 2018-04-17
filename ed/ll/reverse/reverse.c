#include<stdio.h>
#include"link.h"

Node *head = NULL; 

int main(){
	print(head);
	head = Reverse(head);
	print(head);

	return 0;
}


