#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>
#include <sys/time.h>

struct message
{
long int msg_type;/*---------*/
char text[100];
};

int main()
{
fd_set readfds;
struct timeval tv;
int fd_stdin=fileno(stdin);
char buffer[10];
int running=1;
int id1,id2,num_readable;
struct message msg_1t2;
struct message msg_2t1;
long int msg_to_receive=12;/***********/
msg_2t1.msg_type=21;


id1=msgget(123,0644|IPC_CREAT);
if(id1<0)
	{
	printf("msgget Failed\n");
	exit(0);
	}
id2=msgget(321,0644|IPC_CREAT);
if(id2<0)
	{
	printf("msgget 2 failed\n");
	exit(0);
	}

/**********************************************/
while(running)
{
FD_ZERO(&readfds);
FD_SET(fileno(stdin), &readfds);
tv.tv_sec = 1;
tv.tv_usec = 0;
A1:
num_readable = select(fd_stdin + 1, &readfds, NULL, NULL, &tv);
if(num_readable == -1)
	goto A1;
if (num_readable == 0)
	{
	if(msgrcv(id1,(void *)&msg_1t2,100,msg_to_receive,IPC_NOWAIT)!=-1)
		{
		printf("Usr1:%s",msg_1t2.text);
		}
	if(strncmp(msg_1t2.text,"end",3)==0)
		{
		printf("hi");
		running=0;
		}
	}
else
	{
	printf("2@:");
	fflush(stdin);
	fgets(buffer,100,stdin);
	strcpy(msg_2t1.text,buffer);
	here:
	if(msgsnd(id2,(void *)&msg_2t1,100,0)==-1)
		{
		goto here;
		}
	if(strncmp(buffer,"end",3)==0)
		{
		running=0;
		goto A2;
		}
	}
}
if(msgctl(id2,IPC_RMID,0)==-1)
	{
	fprintf(stderr,"msgctl fail");
	exit(0);
	}

A2:
if(msgctl(id1,IPC_RMID,0)==-1)
	{
	fprintf(stderr,"msgctl fail");
	exit(0);
	}


exit(1);
}
