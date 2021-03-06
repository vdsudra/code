#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
void ReadDir(char *path);
int find_size(char *path);
int main(int argc, char *argv[])
{
   if(argc != 2)
   {
      printf("Invalid Number Of arguments\n");
      return 1;
   }
   find_size(argv[1]);
   return 0;
}

int find_size(char *path)
{
   struct stat st;
   if((stat(path, &st)) < 0)
   {
      perror("Error(find_size)");
   }
   else if(S_ISDIR(st.st_mode))
   {
      ReadDir(path);
   }
   else
   {
      printf("%s\t:%d\n",path,(int)st.st_size);
   }
   return 0;
}

void ReadDir(char *path)
{
   struct stat st;
   DIR *directory = NULL;
   struct dirent *dir_path = NULL;
   char temp[1024] = {0};
   do
   {
      directory = opendir(path);
      if(directory  == NULL)
      {
         perror("Error(ReadDir)");
         break;
      }

      while((dir_path=readdir(directory)) != NULL)
      {
         if((strcmp(dir_path->d_name,"..")==0) || (strcmp(dir_path->d_name,".")==0))
            continue;
         snprintf(temp,1024,"%s/%s",path,dir_path->d_name);
         stat(temp, &st);
         if(S_ISDIR(st.st_mode))
         {
            ReadDir(temp);
         }
         else
         {
            printf("%s\t:%d\n",temp,(int)st.st_size);
         }

      }
   }while(0);
   if(directory != NULL)
      closedir(directory);
}
