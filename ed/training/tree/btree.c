#include<stdio.h>
#include<stdlib.h>

typedef struct __node
{
int data;
struct __node *l;
struct __node *r;
}node;

node *root=NULL;
node *add()
{
	node *tmp=NULL;
	if((tmp=(node*)malloc(sizeof(node))) == NULL)
		return NULL;
	else 
	{
		tmp->l=tmp->r=NULL;
		return tmp;
	}
}

void print(node *tmp)
{
	if(tmp==NULL)
		return ;
	if(tmp->l != NULL)
		print(tmp->l);

	if(tmp->r != NULL)
		print(tmp->r);
	//printf("   | %p |\n",tmp);
	//printf("%p | %d | %p\n",tmp->l,tmp->data,tmp->r);
	printf(" %d ",tmp->data);

}

void insert( node *tmp, int d)
{
	if(tmp==NULL)
	{
		node *t=add();
		if(t==NULL)
		{
			printf("Error\n");
			return ;
		}
		t->data=d;
		root=t;
		return ;
	}

	if((tmp->data >= d) && (tmp->l == NULL))
	{
		node *t=add();
		if(t==NULL)
		{
			printf("Error\n");
			return ;
		}
		t->data=d;
		tmp->l=t;
	}

	else if((tmp->data < d) && (tmp->r == NULL))
	{

		node *t=add();
		if(t==NULL)
		{
			printf("Error\n");
			return ;
		}
		t->data=d;
		tmp->r=t;

	}
	else if((tmp->data > d) && (tmp->l == NULL))
	{
		node *t=add();
		if(t==NULL)
		{
			printf("Error\n");
			return ;
		}
		t->data=d;
		tmp->l=t;
	}
	else if( (tmp->data > d) && (tmp->l != NULL) )
		insert(tmp->l,d);
	else
		insert(tmp->r,d);
}

int size(node *tmp)
{
	if(tmp == NULL)
		return 0;
	else 
		return 1+size(tmp->l)+size(tmp->r);
}

void inorder(node *t) //12345
{
	if(t==NULL)
		return;
	inorder(t->l);
	printf("%d ",t->data);
	inorder(t->r);
}

int minval(node *t) 
{
	if(t->l == NULL)
		return t->data;
	else
		return minval(t->l);
}

int search(node *t, int x)
{
	if(t==NULL)
		return 0;
	if(t->data == x)
		return 1;
	if(t->data > x)
		return search(t->l,x);
	else if(t->data < x)
		return search(t->r,x);
	else
		return 0;
}
 
int main()
{
	insert(root,10);
	insert(root,17);
	insert(root,3);
	insert(root,9);
	insert(root,15);
	insert(root,33);
	insert(root,1);
	insert(root,18);
	insert(root,12);
	print(root);
	printf("\n");
	printf("No Of Nodes:%d\n",size(root));
	int i=0;
	node *t=root;
/*
	while(t != NULL)
	{
		if(t->l != NULL)
		{
			t=t->l;
			i++;
			continue;
		}
		if(t->r != NULL)
		{
			t=t->r;
			i++;
			continue;
		}
		i++;
		break;
	}
	printf("No Of Nodes using loop:%d\n",i);
*/

printf("In Order\n");
inorder(root);
printf("Min:%d\n",minval(root));
printf("Search:%d\n",search(root,100));

}
