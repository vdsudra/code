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

