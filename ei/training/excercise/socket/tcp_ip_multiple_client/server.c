#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
void *connection_handler(void *socket_desc);
int main()
{
int client_fd,server_fd,*new_sockid;

socklen_t cl_len,sr_len;

struct sockaddr_in sk_addr,cl_addr;

server_fd=socket(AF_INET,SOCK_STREAM,0);	
sk_addr.sin_family=AF_INET;
sk_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
sk_addr.sin_port=8000;
sr_len=sizeof(sk_addr);
bind(server_fd,(struct sockaddr *)&sk_addr,sr_len);
listen(server_fd,5);  /*---------------------*/
printf("server waiting for client\n");
cl_len=sizeof(cl_addr);

while((client_fd= accept(server_fd,(struct sockaddr *)&cl_addr,&cl_len))>0)/*-----------------*/
	{
	printf("connection accepted...\n");
	pthread_t my_thread;
	new_sockid = malloc(1);
	
	*new_sockid = client_fd;
	if(pthread_create(&my_thread,NULL,connection_handler,(void*)new_sockid)<0)
	{
	    printf("could not create thread\n");
	    return 1;
	}

	}
printf("Failed\n");
return 0;

}

void *connection_handler(void *socket_desc)
{
int sock = *(int*)socket_desc; //convert pointer to intg
int read_size;
char client_message[100];
while((read_size=recv(sock,client_message,100,0))>0)
{
printf("Message:%s",client_message);
}
if(read_size==0)
	{
	puts("Client disconnected");
	}
else if(read_size==-1)
	{
	perror("recv failed");
	}

free(socket_desc);
printf("1\n");
return 0;
}

//MSG_DONTWAIT
