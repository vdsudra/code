#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void cat_cmd(int arg_c, char *arg_v[]);
void copy_file(int arg_c, int temp, char *arg_v[]);

int main(int argc, char *argv[])
{
   if(argc < 2)
   {
      while(1)
         printf("");
   }
   else
   {
      cat_cmd(argc, argv);
   }
   return 0;
}

void cat_cmd(int arg_c, char *arg_v[])
{
   int fd = 0;
   int i = 0, j = 0, temp = 0;
   char buffer[1024]={0};

   for(j=2; j < arg_c; j++)
   {
      if(((strcmp(arg_v[j], ">>"))==0) || ((strcmp(arg_v[j], ">"))==0) )
      {
         temp=j;
         copy_file(arg_c,temp,arg_v);
         return ;
      }
   }
   do
   {
      for(i=1; i < arg_c; i++)
      {
         if(( fd = open(arg_v[i], O_RDONLY)) == -1)
         {
            perror("Error");
            break;
         }
         while( (read(fd,buffer,1024)) > 0)
         {
            printf("%s",buffer);
         }
         memset(buffer,0x00,1024);
         close(fd);
      }
   }while(0);
   if(fd != 0)
      close(fd);
}

void copy_file(int arg_c, int temp, char *arg_v[])
{
   int i = 0;
   int fd_w = 0, fd_r = 0;
   char buffer[1024] = {0};

   do
   {
      if(strcmp(arg_v[temp],">" )==0)
      {
         if(( fd_w = open(arg_v[arg_c-1], O_WRONLY)) == -1)
         {
            perror("Error");
            break;
         }
      }
      else
      {
         if(( fd_w = open(arg_v[arg_c-1], O_WRONLY | O_APPEND)) == -1)
         {
            perror("Error");
            break;
         }
      }
      for(i = 0; i < temp ; i++)
      {
         if(( fd_r = open(arg_v[i], O_RDONLY)) == -1)
         {
            perror("Error");
            break;
         }
         while((read(fd_r, buffer, 1024 )) > 0)
         {
            write(fd_w, buffer, strlen(buffer));
         }
         close(fd_r);
      }
   }while(0);
   if(fd_w > 0)
      close(fd_w);
   if(fd_r > 0)
      close(fd_r);
}
