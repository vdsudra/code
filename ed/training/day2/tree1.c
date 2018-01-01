#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct __node 
{
	int data;
	struct __node *left;
	struct __node *right;
}Node;

bool IsLess(Node *tmp, int val);
bool IsBST(Node *tmp);
bool IsGre(Node *tmp, int val);
Node *Add(int d);
Node *Insert(Node *,int );
Node *root = NULL;
Node *Insert(Node *tmp,int d)
{
	if(tmp== NULL)
	{
		tmp=Add(d);
	}

	else if(d <=(tmp->data))
	{
		Insert((tmp -> left), d);
	}

	else	
	{
		Insert((tmp -> right), d);
	}
	return tmp;
}

bool IsBST(Node *tmp)
{
	if(tmp == NULL)
		return true;
	if(IsLess(tmp->left,tmp->data) && IsGre(tmp->right,tmp->data) && IsBST(tmp->left) && IsBST(tmp->right))
		return true;
	else
		return false;
}

bool IsLess(Node *tmp, int val)
{
	if(tmp == NULL)
		return true;

	if(tmp-> data <= val && IsLess(tmp->left,val) && IsLess(tmp->right,val))
		return true;
	else 
		return false;

}

bool IsGre(Node *tmp, int val)
{
	if(tmp == NULL)
		return true;

	if(tmp-> data > val && IsGre(tmp->left,val) && IsGre(tmp->right,val))
		return true;
	else 
		return false;

}


int Search(Node *tmp, int d)
{
	if(tmp==NULL)
	{
		printf("Not Available\n");
		return 0;
	}
	else if(tmp->data == d)
	{
		printf("Found:%p %d\n",tmp,tmp->data);
		return 0;
	}
	else if(d <= tmp->data)
	{
		return Search(tmp->left, d);
	}
	else
	{
		return Search(tmp->right, d);
	}
}
Node *Add(int d)
{
	Node *tmp=(Node *)malloc(sizeof(Node));
	if(NULL == tmp)
	{
		printf("Failed To allocate memory\n");
		return NULL;
	}
	tmp->data=d;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}

/*
Node *Del(Node *tmp, int d)
{

	if(tmp == NULL)
	{
		return tmp;
	}

	else if(tmp->data < d)
	{
		tmp->left=Del(tmp->left, d);
	}
	else if(tmp->data > d)
	{
		tmp->right=Del(tmp->right,d);
	}
	else
	{
		if(tmp->left == NULL && tmp->right == NULL)
		{
			free(tmp);
			tmp=NULL;
		}
		else if(tmp->left == NULL)
		{
			Node *t1=tmp;
			tmp= tmp->right;
			free(tmp);
			tmp=t1;
		}
		else if(tmp->right == NULL)
		{
			Node *t1=tmp;
			tmp= tmp->left;
			free(tmp);
		}
		else
		{
			Node *t=Findmin(tmp->right);
			tmp->data= t->data;
			tmp->right=delete(tmp->right, t->data);
		}
	}
	return tmp;
}
*/
int main()
{

	root=Insert(root,5);
	root=Insert(root,15);
	root=Insert(root,55);
	root=Insert(root,9);
	printf("%p\n",root);
	//printf("Tmp:%p Data:%d\n",tmp,tmp->data);

	Search(root,55);


}

