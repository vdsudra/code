#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/un.h>
#include<sys/socket.h>
int main()
{
   char running=1;
   int client1_fd,client2_fd,server_fd;
   socklen_t client1_len,client2_len,server_len;
   char str[15];
   char hl[]="Hello";
   struct sockaddr_un server,client1,client2;
   unlink("server_socket");   /*To remove the socket if it already exists*/
   server_fd=socket(AF_UNIX,SOCK_STREAM,0);/*----------*/
   server.sun_family=AF_UNIX;
   strcpy(server.sun_path,"server_socket");
   server_len=sizeof(server);

   bind(server_fd,(struct sockaddr *)&server,server_len);   /*To bind that to an address in the Unix domain*/
   /* Instructs the socket to listen for incoming connections from client programs,5, is the number of incoming connections that can be queued before you call accept() */
   listen(server_fd,5);  /*---------------------*/
   printf("server waiting for client\n");
   client1_len=sizeof(client1);
   client1_fd=accept(server_fd,(struct sockaddr *)&client1,&client1_len);/*-----------------*/
   printf("client 1 connected...\n");
   /*
      client2_len=sizeof(client2);
      client2_fd=accept(server_fd,(struct sockaddr *)&client2,&client2_len);
      printf("client 2 connected...\n");*/
   while(running==1)
   {
      //read(client1_fd,&str,15);
      recv(client1_fd,str,15,0);
      printf("Client1: %s",str);
      if(strncmp("end",str,3)==0)
         running=0;
      strcat(str,hl);
      send(client1_fd,str,sizeof(str),0);
      /*sleep(5);
        recv(client2_fd,str,15,0);
        printf("Client2: %s",str);
      //write(client_fd,&ch,1);*/
   }
   close(client1_fd);
}
