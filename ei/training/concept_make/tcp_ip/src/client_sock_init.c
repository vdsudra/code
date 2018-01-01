int ClientInitSock(int *sock_fd)
{
	socklen_t cl_len;
	int result;
	printf("1\n");
	if((*sock_fd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("Error:");
		return 0;
	}
	cl_addr.sin_family=AF_INET;
	cl_addr.sin_addr.s_addr=inet_addr(ADD);
	cl_addr.sin_port=PRT;
	cl_len=sizeof(cl_addr);
	result=connect(*sock_fd,(struct sockaddr *)&cl_addr,cl_len);/*--------------*/
	if (result == -1)
	{
		printf("Connect failed\n");
		close(*sock_fd);/*--------------------------*/
		return 0;
	}
return 0;
}

