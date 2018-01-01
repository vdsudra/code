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
    int running=1,client_fd,server_fd;
    char buffer[10];
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
    client_fd=accept(server_fd,(struct sockaddr *)&cl_addr,&cl_len);/*-----------------*/
    printf("client connected...\n");
    while(running==1)
    {
        recv(client_fd,buffer,15,0);
        printf("Client: %s",buffer);
        if(strncmp("end",buffer,3)==0)
            running=0;
        sleep(2);
    }
    close(client_fd);
    exit(0);
}
