#include"common.h"
int ServerInitSock(int *serFd,int *cliFd)
{
	SocketStructure socket_addr,client_addr;
	if((*serFd = socket(AF_INET,SOCK_STREAM,0))==-1)	
	{
		perror("Error:");
		return -1;
	}
	socket_addr.sin_family=AF_INET;
	socket_addr.sin_addr.s_addr=inet_addr(ADD);
	socket_addr.sin_port=PRT;
	socklen_t sr_len=sizeof(socket_addr);
	bind(*serFd,(struct sockaddr *)&socket_addr,sr_len);
	listen(*serFd,5);  /*---------------------*/
	printf("server waiting for client\n");
	socklen_t cl_len=sizeof(client_addr);
	*cliFd=accept(*serFd,(struct sockaddr *)&client_addr,&cl_len);/*-----------------*/
	printf("client connected...\n");
	return 0;
}
