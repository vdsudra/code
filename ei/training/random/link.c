#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct movie
{
   char name[1024];
   struct movie *next;

};

struct screen
{
   int id;
   struct movie mov; // Add structure
   struct screen *next;
};

struct screen *Shead =NULL;

int main()
{
   int op;
   int id;
   while(1)
   {
      printf("Enter Option\n");
      printf("1 to Insert Screen\n");
      printf("2 to Insert movie\n");
      printf("3 to Traverse movie\n");
      printf("4 to Exit\n");
      scanf("%d",&op);
      switch(op)
      {
         case 1:
            {
               printf("Enter screen id:  ");
               scanf("%d",&id);
               InsertScreen(id);

               break;
            }

         case 2:
            {
               printf("Enter screen id: ");
               scanf("%d",&id);
               InsertMovie(id);
               break;
            }
         case 3:
            {
               printf("Enter screen id:  ");
               scanf("%d",&id);
               TraversalMovie(id);
               break;
            }
         case 4:
            {
               return 0;
            }
         default :
            {
               printf("Invalid Option\n");
            }
      }
   }
}

int InsertScreen(int sid)
{
   struct screen *Stemp =NULL;
   Stemp = (struct screen *)malloc(sizeof(struct screen));
   if (Stemp == NULL)
      return -1;
   Stemp->next=Shead;
   Stemp->id=sid;
   Shead=Stemp;
   Stemp->mov.next=NULL;
   strcpy(Stemp->mov.name,"List....");
}




int InsertMovie(int sid)
{
   char name[1024]={0};
   struct movie *Mtemp =NULL;
   struct screen *Stemp =NULL;
   Stemp = Shead;

   while(Stemp != NULL)
   {
      if(Stemp->id == sid )
      {
         Mtemp = (struct movie *)malloc(sizeof(struct movie));
         if (Mtemp == NULL)
            return -1;
         strcpy(Mtemp->name,name);
         printf("Enter movie Name\n");
         scanf("%s",name);
         Mtemp->next=Stemp->mov.next;
         Stemp->mov.next=NULL;
      }
      Stemp=Stemp->next;
   }
}


int TraversalMovie(int sid)


{

   struct movie *Mtemp =NULL;
   struct screen *Stemp =NULL;
   Stemp = Shead;

printf("In\n");
   while(Stemp != NULL)
   {
      if(Stemp->id == sid)
      {
printf("Match\n");
         Mtemp = Stemp->mov.next;


         printf("%s\n",Stemp->mov.name);
         while(Mtemp != NULL)
         {
            printf("%s\n",Mtemp->name);
            Mtemp=Mtemp->next;
         }

      }


      Stemp=Stemp->next;

   }



}




































































