#include<stdio.h>
#include<stdlib.h>

int top=0;
char arr[100];
int push(char ch)
{
	arr[top++]=ch;
}

char Top()
{
	return arr[top];
}

int pop()
{
	if(top == 0)
	{
		printf("Empty\n");
		return;
	}

	top--;
	return;
}

int main()
{
	char s[100]="dk{0(12)cc}";
	int l=strlen(s);
	char c;
	int i;
	for(i=0;i<l;i++)
	{
		if(s[i] == '(' || s[i] == '{'  || s[i] == '[')
		{
			push(s[i]);
		}
		else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			c=Top();
			if( (top == 0) || (s[i] != c))
			{
				printf("Wrong\n");
				return;
			}
			pop();
		}
	}
		printf("Correct\n");
}

