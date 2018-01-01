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


node *rev(node *t1, node *t2)
{
	node *t3=NULL;
	if(t2 != NULL)
	{
		t3=t2->next;
		t2->next=t1;
		return rev(t2,t3) ;
	}
	else
	{
		head->next=NULL;
		return t1;
	}
}
void revll(node *tmp)
{
	node *t=head;
	head=rev(head, head->next);
	t->next=NULL;
	return;
}


int main()
{
	add(1);
	add(2);
	add(3);
	print();
	head=rev(head, head->next);
	print();
}
