#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<pthread.h>

#define ADD "127.0.0.1"
#define PRT 8000
void *SendMsg(void *);
void *RcvMsg(void *);
int ServerInitSock(int *serFd,int *cliFd);
int ClientInitSock(int *sock_fd);
typedef struct sockaddr_in SocketStructure;
int running=1;
