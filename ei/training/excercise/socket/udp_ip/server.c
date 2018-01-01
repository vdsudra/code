#include<stdio.h>
#include<stdlib.h>
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
    struct sockaddr_in server_addr,client_addr;//contain the ip address and port of the client that sent the message
    socklen_t client_len,server_len;
    int server_fd;
    char buffer[1024];
    if((server_fd=socket(AF_INET,SOCK_DGRAM,0))<0)
    {
        printf("socket() Failed\n");
        exit(0);
    }
    memset((char *)&server_addr,0,sizeof(server_addr));// zero out the structure
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_addr.sin_port=8000;
    server_len=sizeof(server_addr);
    if((bind(server_fd,(struct sockaddr *)&server_addr,server_len))<0)
    {
        printf("bind() Failed\n");
        exit(0);
    }
    server_len=sizeof(client_addr);
    printf("Waiting for client\n");
    while(strncmp("end",buffer,3)!=0)
    {
        recvfrom(server_fd,buffer,sizeof(buffer),0,(struct sockaddr *)&client_addr,&client_len);
        printf("Received:%s",buffer);
    }
    close(server_fd);
    exit(0);
}
