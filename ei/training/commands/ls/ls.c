#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

void find_dir(char *arg_1, char *arg_2);
void display(char path[1024], char flag[10]);
int main(int argc, char *argv[])
{
   if(argc > 2)
{
printf("Invalid Number Of Arguments\n");
      return 1;
}
   find_dir(argv[1], argv[2]);
}

void find_dir(char *arg_1, char *arg_2)
{
   char pwd[1024] = {0};
   do
   {
      if((arg_1 == NULL)  || ((arg_2 == NULL) && (arg_1[0] == '.'))) 
      {
         if(getcwd(pwd, sizeof(pwd)) == NULL)
         {
            perror("Error(pwd)");
            break;
         }
         display(pwd,NULL);
      }
      else if((arg_1[0] == '-') && ((arg_2 == NULL) || (arg_2[0] == '.'))) 
      {
         if(getcwd(pwd, sizeof(pwd)) == NULL)
         {
            perror("Error(pwd)");
            break;
         }
         display(pwd,arg_1);

      }
      else if( (arg_2 == NULL) && (arg_1[0] != '-') )
      {
         display(arg_1, NULL);
      }

      else 
      {
         display(arg_2, arg_1);
      }
   }while(0);
}

void display(char path[1024], char flag[10])
{
   struct passwd *usr = NULL;   
   struct group *grp = NULL;
   DIR *dir_ptr = NULL;
   struct dirent *dir_path = NULL;
   struct stat stat_buff;
   char buffer[1024] = {0};
   int sum = 0;
   int i =0;
   int len = 0;
   do
   {
      if(flag != NULL)
      {
         len = strlen(flag);
         for(i=1; i<len; i++)
         {
            sum=sum + flag[i];
         }
         if((sum != 97) && (sum != 108) && (sum != 205))
         {
            printf("Invalid option selected, use -l -a -la  or -al\n");
            break;
         } 
      }

      if((dir_ptr = opendir(path)) == NULL)
      {
         perror("Error");
         break;
      }
      while((dir_path = readdir(dir_ptr)) != NULL)
      {
         //if((strcmp(dir_path->d_name, ".") == 0) || (strcmp(dir_path->d_name, "..") == 0 ))
         //   continue;
         snprintf(buffer, 1024, "%s/%s", path, dir_path->d_name);
         if(stat(buffer, &stat_buff) < 0)
         {
            perror("Error(stat)");
            continue;
         }
         if(sum < 98)
         {
            if(sum == 0)
            {
               if(dir_path->d_name[0] == '.')
                  continue;
            }
            printf("%s\t", dir_path->d_name);
         }

         else if (sum > 100)
         {
            if(sum == 108) 
            {
               if(dir_path->d_name[0] == '.')
                  continue;
            }
            printf((S_ISDIR(stat_buff.st_mode)) ? "d" : "-" );
            printf((stat_buff.st_mode & S_IRUSR) ? "r" : "-");
            printf((stat_buff.st_mode & S_IWUSR) ? "w" : "-");
            printf((stat_buff.st_mode & S_IXUSR) ? "x" : "-");
            printf((stat_buff.st_mode & S_IRGRP) ? "r" : "-");
            printf((stat_buff.st_mode & S_IWGRP) ? "w" : "-");
            printf((stat_buff.st_mode & S_IXGRP) ? "x" : "-");
            printf((stat_buff.st_mode & S_IROTH) ? "r" : "-");
            printf((stat_buff.st_mode & S_IWOTH) ? "w" : "-");
            printf((stat_buff.st_mode & S_IXOTH) ? "x" : "-");
            printf("\t%d", (int)stat_buff.st_nlink);
            usr = getpwuid(stat_buff.st_uid);
            printf("\t%s", usr->pw_name);
            grp = getgrgid(stat_buff.st_gid);
            printf("\t%s", grp->gr_name);
            printf("\t%u",(unsigned int) stat_buff.st_size);
            printf("\t%s", dir_path->d_name);
            printf("\n");
         }
      }
      printf("\n");

   }while(0);
}




