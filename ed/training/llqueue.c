#include<stdio.h>
typedef struct __node
{
	int d;
	struct __node *next;
}node;

node *front=NULL;
node *rear=NULL;

node *mkn()
{
	node *tmp=(node *)malloc(sizeof(node));
	return tmp;
}

int Eq(int data)
{
	//printf("%d\n",__LINE__);
	node *tmp;
	if((tmp=mkn()) == NULL)
	{
		printf("Failed To create Node\n");
		return -1;
	}
	tmp->d=data;

	if(front == NULL)
	{
		rear = front = tmp;
	}
	tmp->next=NULL;
	rear->next=tmp;
	rear = tmp;

}
int print()
{
	node *tmp;
	tmp= front;

	while(tmp != NULL)
	{
	printf("%d ",tmp->d);
	tmp=tmp->next;
	}
	printf("\n");
}

int isempty()
{
	if(front == NULL)
	{
		return 1;
	}
	return 0;
}

int Dq()
{
	if(isempty())
	{
		printf("Empty\n");
		return 0;
	}
	else if(front == rear)
	{
		printf("Empty\n");
		free(front);
		front = rear = NULL;
		return 0;
	}
	node *t=front->next;
	free(front);
	front=t;
}


int main()
{
	Eq(5);
	Eq(1);
	Eq(9);
	Eq(6);
	Eq(7);
	print();
	Dq();	
	print();
	Dq();	
	print();
	Dq();	
	print();
	Dq();	
	print();
	Dq();	
	Dq();	
	Eq(5);
	Eq(1);
	Eq(9);
	print();
}
