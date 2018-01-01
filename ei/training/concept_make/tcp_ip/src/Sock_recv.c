void *RcvMsg(void *cliFd)
{
	int *id=(int *)cliFd;
	char buffer[1024];
	memset(buffer,'\0',1024);	
	while(running==1)
	{
		recv(*id,buffer,1024,0);
		printf("Client:%s",buffer);
		if(strncmp("end",buffer,3)==0)
			running=0;
		sleep(2);
	}
	pthread_exit(NULL);
}
