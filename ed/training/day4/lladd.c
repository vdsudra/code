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

void swap()
{
	node *t1=head;
	node *t2;
	node *t3=t2;
	while(t1->next != NULL)
/*  helpline.lhoahm@sbi.co.in */
	{
		t1->next=t2->next;
		t2->next=t1;
		t1=t1->next;
		if(t1==NULL)
			break;
		t2=t1->next;
	}
	head=t3;
}

int find(node *tmp)
{
	if(tmp != NULL)
	{
		return 1+find(tmp->next);
	}
	else
		return 0;
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
	//swap();
	add(1);
	add(2);
	add(3);
	add(4);
	add(5);
	add(6);
	add(7);
	print();
	printf("Nodes:%d\n",find(head));
}
