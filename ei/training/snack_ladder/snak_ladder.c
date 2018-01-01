#include<stdio.h>

int ladders[20][2]={{3,20},{6,29},{26,63},{34,61}};
int snakes[20][2]={{24,8},{59,7}};
int lad_no =4;
int snk_no=1;
int n=64;
int id=1;
struct path_log
{
   int path_id;
   int path_pos;
   int path[100];
   int counter;
};

int main()
{
   struct path_log path1;
   path1.path_pos=0;
   path1.counter=0;

   find_path(1,path1);  
}

find_path(int pos, struct path_log path1) 
{
   int i,j,k;
   int diff=0;
   path1.path[path1.path_pos]=pos;
   path1.path_pos++;

   while(pos+6<n)
   {
      for(i=0;i<lad_no;i++)
      {
         if(pos<=ladders[i][0])//<=
         {
            diff=ladders[i][0]-pos;
            //   temp=diff;
            while((diff-6) > 0)
            {
               for(j=0;j<snk_no;j++)
               {
                  if((pos+6) == snakes[j][1])
                  {
                     path1.counter++;
                     path1.path[path1.path_pos]=pos-1;
                     path1.path_pos++;

                  }
               }
               path1.counter++;
               pos=pos+6;
               path1.path[path1.path_pos]=pos;
               path1.path_pos++;
               diff=diff-6;
            }
            path1.path[path1.path_pos]=ladders[i][0];
            path1.counter++;
            path1.path_pos++;

            find_path(ladders[i][1],path1);
//            pos=ladders[i][0]-1;
            path1.path_pos--;
//            path1.path[path1.path_pos]=pos;
            path1.counter--;
//            path1.path_pos++;
         }
      }

      for(j=0;j<snk_no;j++)
      {
         if((pos+6) == snakes[j][1])
         {
            path1.counter++;
            path1.path[path1.path_pos]=pos-1;
            path1.path_pos++;

         }
      }
      pos=pos+6;
      path1.counter++;
      path1.path[path1.path_pos]=pos;
      path1.path_pos++;
   }

   path1.counter++;
   path1.path[path1.path_pos]=64;
   path1.path_id=id;
   id++;
   printf("Path:%d\n",path1.path_id);
   printf("Count:%d\n",path1.counter);
   for(i=0;i<=path1.path_pos;i++)
   {
      printf("%d ",path1.path[i]);
   }
   printf("\n\n");

}
