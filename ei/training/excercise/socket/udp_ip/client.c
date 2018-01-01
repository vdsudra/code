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
    struct sockaddr_in client_addr;
    int client_fd,len;
    char buffer[1024];

    memset(buffer,'\0',sizeof(buffer));

    if((client_fd=socket(AF_INET,SOCK_DGRAM,0))==-1)
    {
        printf("socket() Failed\n");
        exit(0);
    }
    client_addr.sin_family=AF_INET;
    client_addr.sin_addr.s_addr=inet_addr("127.0.0.1");//Convert IP addresses from a dots-and-number string to a struct in_addr
    client_addr.sin_port=8000;
    len=sizeof(client_addr);
    /*if(inet_aton("127.0.0.1",&client_addr.sin_addr)==0)
      {
      printf("inet_aton() Failed\n");
      exit(0);
      }*/
    while(strncmp("end",buffer,3)!=0)
    {
        printf("Enter Data To Be Send:");
        fgets(buffer,sizeof(buffer),stdin);
        if(sendto(client_fd,buffer,sizeof(buffer),0,(struct sockaddr *)&client_addr,len)==-1)
        {
            printf("sendto() Failed");
        }
    }
    close(client_fd);
    exit(0);
}
