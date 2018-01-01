#include<stdio.h>
#include<stdlib.h>

typedef struct __node
{
	int data;
	struct __node *next;
}node;

node *head=NULL;

void add(int x)
{
	node *tmp=(node *)malloc(sizeof(node));
	tmp->data=x;
	tmp->next=head;
	head=tmp;
}

void print()
{
	node *tmp=NULL;
	tmp=head;
	while(tmp != NULL)
	{
		printf("%d ",tmp->data);
		tmp= tmp->next;
	}
	printf("\n");
}

void swap(node *t1, node *t2)
{
	node *t=NULL;
	if(t2 != NULL)
	{
		t=t2->next;
		t2->next=t1;
		t1->next=t;
		if(t != NULL && t->next != NULL)
			return swap(t,t->next);
	}
	return;
}

int main()
{
	add(5);
	add(55);
	add(5);
	add(55);
	add(5);
	add(55);
	print();
	swap(head,head->next);
	print();
}
