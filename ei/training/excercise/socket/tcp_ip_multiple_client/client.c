#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main()
{
int running=1,client_fd,result;
char buffer[10];
socklen_t cl_len;
struct sockaddr_in cl_addr;
client_fd=socket(AF_INET,SOCK_STREAM,0);
cl_addr.sin_family=AF_INET;
cl_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
cl_addr.sin_port=8000;
cl_len=sizeof(cl_addr);

result=connect(client_fd,(struct sockaddr *)&cl_addr,cl_len);/*--------------*/
if (result == -1)
	{
	printf("Connect failed\n");
	exit(0);
	}
printf("Connected...\n");

while(running==1)
	{
	printf("Enter data :");
	fgets(buffer,15,stdin);
	if(strncmp("end",buffer,3)==0)
		running=0;
	if(send(client_fd,buffer,sizeof(buffer),0)==-1)
		printf("sending Failed\n");
	sleep(1);

	}

close(client_fd);/*--------------------------*/
exit(1);

}
