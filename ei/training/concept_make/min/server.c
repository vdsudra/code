#include "common.h"
SocketStructure socket_addr,client_addr;
int main()
{
	int res,client_fd,socket_fd;
	pthread_t t_send,t_recv;
	InitSock(&socket_fd,&client_fd);	/* Creating socket*/
	if(socket_fd==-1)
	{
		return 0;
	}
	res=pthread_create(&t_recv,NULL,RcvMsg,&client_fd);	/* thread for recive*/
	if(res!=0)
	{
		perror("Error:");
		close(socket_fd);
	}
	res=pthread_create(&t_send,NULL,SendMsg,&client_fd);  /*thread for send */
	if(res!=0)
	{
		perror("Error:");
		close(socket_fd);
	}
	pthread_join(t_recv,NULL);
	pthread_join(t_send,NULL);
	exit(0);
}





