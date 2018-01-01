#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>

int main()
{
   int sock_fd = 0;
   int len = 0;
   struct sockaddr_un client; 
   int result = 0;
   char str[1024] = {0};

   memset(&client, 0x00, sizeof(client));

   do
   {
      if( 0 > (sock_fd = socket(AF_UNIX,SOCK_STREAM,0)))
      {
         perror("Error");
         break;
      }
      client1.sun_family = AF_UNIX;		
      strcpy(client1.sun_path,"my_socket");	
      len = sizeof(client);

      if(0 > (connect(sock_fd, (struct sockaddr *)&client, len)))
      {
         printf("Connection fail\n");
         break;
      }
      printf("Connected...\n");

      while(strncmp("end", str, 3) != 0)
      {
         printf("Enter data :");
         fgets(str, 15, stdin);
         if(send(sock_fd, str, sizeof(str), 0)==-1)
            printf("sending Failed\n");
         sleep(1);
      }
   }
   while(0);	
   if(sock_fd > 0)
      close(sock_fd);
}
