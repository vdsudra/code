#include "common.h"
SocketStructure socket_addr,client_addr;
int main()
{
	int socket_fd,res;
	pthread_t t_send,t_recv;
	ClientInitSock(&socket_fd);
	if(socket_fd==-1)
	{
		return 0;
	}
	printf("Connected...\n");
	res=pthread_create(&t_recv,NULL,RcvMsg,&socket_fd);	/* thread for recive*/
	if(res!=0)
	{
		perror("Error:");
		close(socket_fd);
		return 0;
	}
	printf("2\n");
	res=pthread_create(&t_send,NULL,SendMsg,&socket_fd);  /*thread for send */
	if(res!=0)
	{
		perror("Error:");
		close(socket_fd);
		exit(1);
	}
pthread_join(t_send,NULL);
pthread_join(t_recv,NULL);
	return 0;

}


