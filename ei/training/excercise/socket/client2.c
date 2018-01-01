#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/un.h>
#include<sys/socket.h>

int main()
{
int running=1;
int sock_fd;
int len;
struct sockaddr_un client; /*UNIX domain socket */
int result;
char str[15];

sock_fd=socket(AF_UNIX,SOCK_STREAM,0);/*---------------------------------*/
client.sun_family=AF_UNIX;		/* AF_UNIX */
strcpy(client.sun_path,"server_socket");	/* pathname */
len=sizeof(client);

result=connect(sock_fd,(struct sockaddr *)&client,len);/*--------------*/
if (result == -1)
	{
	printf("Connect failed\n");
	exit(0);
	}
printf("Connected...\n");

while(running==1)
	{
	printf("Enter data :");
	fgets(str,15,stdin);
	if(strncmp("end",str,3)==0)
		running=0;
	if(send(sock_fd,str,sizeof(str),0)==-1)
		printf("sending Failed\n");
	sleep(1);

	}
	

//write(sock_fd,str,15);
//read(sock_fd,&ip,1);
//printf("character recieved from server=%c\n",ip);

close(sock_fd);
exit(1);
}
