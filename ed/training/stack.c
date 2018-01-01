#include<stdio.h>

int a[10];
int top=-1;

int Top()
{
	if(top==-1)
	{
		printf("Empty\n");
		return;
	}
	printf("%d\n",a[top]);
}

int print()
{
	int i;
	for(i=top;i>=0;i--)
		printf("%d ",a[i]);
	printf("\n");
}

int push(int d)
{
	if(top==9)
	{
		printf("Full\n");
		return 0;
	}
	a[top++]=d;
	return;
}

int pop()
{
	if(top==-1)
	{
		printf("Empty\n");
		return;
	}
	a[top--]=0;
	return;
}

int main()
{
	push(1);
	push(5);
	push(3);
	print();
	Top();
	pop();
	print();
}
