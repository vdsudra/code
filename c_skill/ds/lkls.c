/*
 *  * single_link.c
 *   *
 *    *  Created on: 16-Feb-2016
 *     *      Author: vinay
 *      */
#include<stdio.h>
#include<malloc.h>

int insertend(int);
int insertbeg(int);
int insertpart(int);
int display();
int deletebeg();
int deleteend();
int delpar(int);
int search(int);
int delete();
int rev();

struct node
{
    int data;
      struct node *next;
};

struct node* head;
struct node* tail;
struct node* temp;
int i,n,x,op;
int main()
{
   head=tail=NULL;
   printf("Enter option:\n");
   printf("If you are adding first node then add is as begin\n");
   while(1)
   {
      printf("1)insert\n2)Display\n3)Delete\n4)Search\n5)Exit\n");
      scanf("%d",&op);
      switch(op)
      {
         case 1:
            printf("1)Insert at begin\n2)Insert at end\n"
                  "3)Insert at Particular position\n");
            scanf("%d",&op);

            switch(op)
            {
               case 1:
                  printf("Enter Total numbers to be add:\n");
                  scanf("%d",&n);
                  printf("Enter numbers one by one \n");
                  for(i=0;i<n;i++)
                  {
                     scanf("%d",&x);
                     insertbeg(x);
                  }
                  break;
               case 2:
                  printf("Enter number to be add:\n");
                  scanf("%d",&n);
                  printf("Enter numbers one by one \n");
                  for(i=0;i<n;i++)
                  {
                     scanf("%d",&x);
                     insertend(x);
                  }
                  break;
               case 3:
                  printf("Enter Present number:\n");
                  scanf("%d",&n);
                  insertpart(n);
                  break;
               default:
                  printf("Invalid option..\n");
                  break;
            }
            display();
            break;
         case 2:
            display();
            break;
         case 3:
            deletee();
            display();
            break;
         case 4:
            printf("Enter data to be find\n");
            scanf("%d",&n);
            search(n);
            break;
         case 5:
            return 0;
            break;
         default:
            printf("Invalid option..\n");
            break;

      }
   }
   return 0;
}
/*********************************************/

int insertbeg(int x)
{
   temp=(struct node *)malloc(sizeof(struct node));
   temp->next=head;
   temp->data=x;
   head=temp;
   if(tail==NULL)
      tail=temp;
   return 0;
}

/*********************************************/

int insertend(int x)
{
   temp=(struct node *)malloc(sizeof(struct node));
   temp->next=NULL;
   tail->next=temp;
   temp->data=x;
   tail=temp;
   return 0;
}
/*********************************************/
int insertpart(int x)
{
   struct node* new;
   struct node* tp;
   temp=head;
   while(1)
   {
      if(temp->data==x)
      {
         printf("1)To insert before\n2)To insert after\n");
         scanf("%d",&n);
         if(n==1)
         {
            printf("Enter data to be Enter\n");
            scanf("%d",&x);
            if(temp==head)
            {
               insertbeg(x);
               return 0;
            }
            new=(struct node *)malloc(sizeof(struct node));
            new->data=x;
            new->next=temp;
            tp->next=new;
            return 0;
         }
         else if(n==2)
         {
            printf("Enter data to be Enter\n");
            scanf("%d",&x);
            /*  if(temp==tail)
             *          {
             *                    insertend(x);
             *                              return
             *                              0;
             *                                      }*/
            new=(struct node *)malloc(sizeof(struct node));
            new->data=x;
            new->next=temp->next;
            temp->next=new;
            if(temp==tail)
               tail=new;
            return 0;
         }
         else
         {
            printf("Invalid option\n");
            return 0;
         }
      }
      tp=temp;
      temp=temp->next;
   }
   return 0;
}
/*************************************************************/
int display()
{
   temp=head;
   printf("\n");
   while(temp!= NULL)
   {
      printf("|%d| -->>  %u ",temp->data,temp);
      temp=temp->next;
   }
   printf("\n");
   return 0;
}
/*****************************************************/
int deletee()
{
   printf("Enter your choice\n1)Delete at begin\n2)Delete at end\n"
         "3)Particular data\n");
   scanf("%d",&op);
   switch(op)
   {
      case 1:
         printf("Enter  total numbers to Delete:\n");
         scanf("%d",&n);
         for(i=0;i<n;i++)
            deletebeg();
         break;
      case 2:
         printf("Enter total numbers to be Delete:\n");
         scanf("%d",&n);
         for(i=0;i<n;i++)
            deleteend();
         break;
      case 3:
         printf("Enter data to be Delete:\n");
         scanf("%d",&n);
         delpar(n);
         break;

      default :
         printf("Invalid option\n");
         break;
   }
   return 0;

}

/*************************************************/
int deletebeg()
{
   temp=head->next;
   free(head);
   head=temp;
   return 0;
}
/**********************************/
int deleteend()
{
   struct node* tp;
   temp=head;
   tp=temp;
   while(temp->next!=NULL)
   {
      tp=temp;
      temp=temp->next;
   }
   free(temp);
   tp->next=NULL;
   tail=tp;
   return 0;
}
/****************************************/
int delpar(int n)
{
   struct node* tp;
   temp=head;
   while(temp->next!=NULL)
   {
      while(temp->data!=n)
      {
         tp=temp;
         temp=temp->next;
      }
      if(temp==head)
      {
         head=temp->next;
         free(temp);
         return 0;
      }
      tp->next=temp->next;
      free(temp);
      return 0;
   }
   return 0;
}
/***************************************************/
int search(int x)
{
   struct node* temp;
   temp=head;
   while(temp->next!=NULL)
   {
      if(temp->data==x)
      {
         printf("%d is present at location %u\n",x,temp);
         return 0;
      }
      else
         temp=temp->next;
   }
   if(temp->data==x)
   {
      printf("Data is present at location %u\n",temp->next);
      return 0;
   }
   printf("No data found...\n");
   return 0;
}

int rev()
{

   struct node* temp=head;
   struct node* dummy=NULL;

   while(head->next != NULL)
   {
      dummy=head->next->next;
      head->next=head;
      head=dummy;
   }
   
   

}
