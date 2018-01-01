#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/un.h>

struct thread_arg 
{
   int client_no;
   int client_fd;
};

void *con_hand(void *sock_fd);

int main()
{
   int server_fd = 0;
   int client_fd = 0;
   socklen_t server_len = 0;
   socklen_t client_len = 0;
   struct sockaddr_un server_str;
   struct sockaddr_un client_str;
   struct thread_arg my_arg;
   pthread_t pid = 0;
   int client_id = 1;
   memset(&server_str, 0x00, sizeof(struct sockaddr_un));
   memset(&client_str, 0x00, sizeof(struct sockaddr_un));
   memset(&my_arg, 0x00, sizeof(my_arg));
   do
   {
      unlink("my_socket");
      if( 0 > (server_fd = socket(AF_UNIX, SOCK_STREAM, 0)))
      {
         perror("Error(socket)");
         break;
      }
      server_str.sun_family = AF_UNIX;
      strcpy(server_str.sun_path, "my_socket");
      server_len = sizeof(server_str);
      if(0 > (bind(server_fd, (struct sockaddr *)&server_str, server_len)))
      {
         perror("error(bind)");
         break;
      }

      if(0 > (listen(server_fd, 5)))
      {
         perror("Error(listen)");
         break;
      }
      client_len = sizeof(struct sockaddr_un);
      while(1)
      {      
         if(0 > (client_fd = accept(server_fd, (struct sockaddr *)&client_fd, &client_len)))
         {
            perror("Error(accept)");
            continue;
         }
         printf("Client %d request to connect\n",client_id);
         pid = 0;
         my_arg.client_fd = client_fd;
         my_arg.client_no = client_id;
         if((pid = pthread_create(&pid, NULL, con_hand, (void *)&my_arg)) < 0)
         {
            perror("Error(thread_create)");
            close(client_fd);
            continue;
         }
         client_id++;
      } 
   }while(0);

   if(0 < server_fd)
      close(server_fd);

}

void *con_hand(void *sock_arg)
{
   int fd = 0;
   int id = 0;
   char buffer[1024] = {0};
   struct thread_arg *arg = NULL;
   arg = (struct thread_arg *)sock_arg;
//   fd = arg->client_fd;
   //   id = arg->client_no;
fd = *(int *) (sock_arg + sizeof(int));
id = *(int *) sock_arg ; 
   while(1)
   {
      if(0 > recv(fd, buffer, 1024, 0))
      {
         perror("Error(recv)");
      }
      else
      {
         printf("Client %d :%s", id, buffer);
      }
      if(strncmp(buffer, "end" ,3) == 0)
         break;
   }
   if(fd > 0)
      close(fd);

}
