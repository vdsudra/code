#include<stdio.h>
#define N 10

int i;
int arr[N];
int front=-1;
int rear=-1;
int isfull()
{
	if(rear == front)
	{
		return 1;
	}
	return 0;
}

int isempty()
{
	if(front == -1)
	{
		return 1;
	}
	return 0;
}


int Enq(int x)
{
	int p;
	if(isfull())
	{
		printf("Queue Is Full\n");
		return;
	}

	if(isempty())
	{
		rear=-1;
		front=-1; 
	}
	else
	{
p=(rear+1)%N
if(p > front)
{
printf("Full\n");
return ;
}



	arr[rear++]=x;
	}

}

int Dq()
{
	if(isempty())
	{
		printf("Queue Is Empty\n");
		front=-1;
		rear=-1; 
	}
	else
	{
		arr[front++]=0;
	}

}
int main()
{
	int data;
	int i;
	Enq(5);
	Enq(1);
	Enq(3);
	Enq(9);
	for(i=front;i<=rear;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	Dq();
	Dq();
	Dq();
	Dq();
	i=rear;
	for(i=front;i<=rear;i++)
		printf("%d ",arr[i]);
	printf("\n");
	Enq(650);
	Enq(100);
	Enq(999);
	for(i=front;i<=rear;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
