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

void printrev(node *tmp)
{
	if(tmp != NULL)
	{
		if(tmp -> next != NULL){
			printrev(tmp -> next);
		}
		printf("%d ",tmp->data);
	}
}
void swap()
{
	node *t1=head;
	node *t2;
	node *t3=t2;
	while(t1->next != NULL)
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

void removedup(){
	node *t1,*t2=NULL;
	node *prev = NULL;
	t1 = head;
	if(t1 == NULL)
		return ;
	while(t1 != t2){
		t2 = t1->next;
		while(t2 != NULL){
			//printf("T1 : %d , T2: %d\n",t1->data, t2->data);
			if(t1->data == t2->data){
				prev->next = t2->next;
				free(t2);
				t2 = prev->next;
			}
			else{
				prev = t2;
				t2 = t2->next;
			}
		}
		t1 = t1-> next;
	}
}

int main()
{
	add(1);
	add(2);
	add(3);
	add(4);
	add(5);
	add(7);
	add(2);
	add(6);
	add(7);
	print();
	removedup();
	print();
	
	//printrev(head);
	//printf("\n");
	printf("Nodes:%d\n",find(head));
}
