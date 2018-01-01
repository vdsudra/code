#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <string.h>
int main(void)
{
   struct dirent **DateList;
   int n;
   int i;
   int j;
   char temp[16];
   int tmp;
   struct tm tm1;
   struct tm tm2;
   time_t t1;
   time_t t2;
   double diff=0;
   memset(&tm1, 0x00, sizeof(tm1));
   memset(&tm2, 0x00, sizeof(tm2));

   n = scandir("/home/vinay/training/short_dir", &DateList, 0,alphasort);
   if (n < 0)
      perror("scandir");
   else
   {
      printf("%d\n",n);
      for(i=0;i<n;i++)
      {
         if ((NULL != strptime(DateList[i]->d_name, "%m_%d_%Y", &tm1)))
         {
            t1=mktime(&tm1);
            printf("T1:%d\n",t1);
            for(j=i+1;j<n;j++)
            {
               if ((NULL != strptime(DateList[j]->d_name, "%m_%d_%Y", &tm2)))               
               {

                  t2=mktime(&tm2);
                  printf("T2:%d\n",t2);
                  diff=t1-t2;
                  printf("Diff:%f\n",diff);
                  if(diff > 0)
                  {
                     strcpy(temp,DateList[i]->d_name);
                     strcpy(DateList[i]->d_name,DateList[j]->d_name);
                     strcpy(DateList[j]->d_name,temp);
                     t1=t2;
                  }
               }
            }
         }
      }

      for(i=0;i<n;i++)
      {
         if ((NULL != strptime(DateList[i]->d_name, "%m_%d_%Y", &tm1)))

         {

            printf("%s\n", DateList[i]->d_name);
         }
         free(DateList[i]);
      }
      free(DateList);
   }
}
