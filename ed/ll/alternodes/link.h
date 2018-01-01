#include<stdlib.h>
typedef struct __node
{
   int data;
   struct __node *next;
}Node;

Node *add(int d, Node* h)
{
   Node *t=(Node*)malloc(sizeof(Node));
   if(t==NULL)
   {
      printf("Malloc failed, Failed to Add %d\n",d);
      return h;
   }

   t->data = d;
   t->next = h;
   return t;
}

void print(Node *h)
{
   while(h != NULL)
   {
      printf("%d ",h->data);
      h=h->next;
   }
   printf("\n");
}

void printAdd(Node *h)
{
   while(h != NULL)
   {
      printf("|%p|-->%d ",h, h->data);
      h=h->next;
   }
   printf("\n");
}

Node* EvenOdd(Node *h){
	Node *odd, *todd, *even, *teven, *tmp;
	odd = todd = even = teven = NULL;
	tmp = h;
	while(tmp != NULL){
		if(tmp->data % 2 != 0){
			if(todd == NULL){
				todd = odd = tmp;
			}
			else
			{
				odd =odd -> next = tmp;
			}
		}

		else{
			if(teven == NULL){
				teven = even = tmp;
			}
			else
			{
				even = even -> next = tmp;
			}
		}

		tmp = tmp->next;
	}
	odd->next= NULL;
	even->next = todd;
	return teven;
}

Node *SwapNode(Node *head){
	Node *curr, *prev, *next, *tmp;
	prev = curr = head;
	while(curr != NULL && curr->next != NULL){
		tmp = curr->next;
		next = tmp->next;
		tmp->next = curr;
		curr->next = next;
		
		if(head == curr)
			head = tmp;
		else 
			prev->next = tmp;
		prev = curr;
		curr = next;
	}

	return head;
}

