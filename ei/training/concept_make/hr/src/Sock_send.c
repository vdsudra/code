#include"common.h"
void *SendMsg(void *cliFd)
{
	int *id=(int *)cliFd;
	char buffer[1024];
	while(running==1)
	{	
		printf("Enter data :");
		fgets(buffer,1024,stdin);
		if(strncmp("end",buffer,3)==0)
			running=0;
		if(send(*id,buffer,sizeof(buffer),0)==-1)
			printf("sending Failed\n");
		sleep(1);
	}
	pthread_exit(NULL);
}
