#include<stdio.h>
#include<stdlib.h>

int stack[10];
int top=0;

int push(int x)
{
	stack[top++]=x;
}

int pop()
{
	int d=stack[--top];
	return d;
}

int expr(char ch)
{
	int a,b;
	int c;
	b=pop();
	a=pop();
	if(ch == '+')
	{
		c=a+b;
	}
	else if(ch == '-')
	{
		c=a-b;
	}
	else if (ch == '*')
	{
		c=a*b;
	}
	push(c);
}
int main()
{
	char arr[10]="23*54*+9-";
	int i;
	for(i=0;i<10;i++)
	{
		if(arr[i] > 48 && arr[i]<58)
		{
			push(arr[i]-48);
		}
		else
		{
			expr(arr[i]);
		} 
	}
	i=pop();
	printf("Ans:%d\n",i);
}

