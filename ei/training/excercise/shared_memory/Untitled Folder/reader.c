#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h> 
#include<sys/shm.h>
#include<string.h>
int main()
{
int shm_id;
char *data;
char buffer[100];

shm_id=shmget(123,100,IPC_CREAT|0644);
if(shm_id==-1)
	{
	printf("semget Failed\n");
	exit(0);
	}
printf("id=%d\n",shm_id);
data=shmat(shm_id,(void *)0,0);
if(data==(char *)-1)
	{
	printf("semat Failed\n");
	exit(0);
	}
while(strncmp("end",buffer,3)!=0)
	{
	strncpy(buffer,data,sizeof(buffer));
	printf("You Wrote : %s",buffer);
	sleep(1);
	}
if(shmdt(data)==-1)
	{
	printf("shmdt failed\n");
	exit(0);
	}
if(shmctl(shm_id,IPC_RMID,0)==-1)
{
	printf("shmctl failed\n");
	exit(0);
}
exit(1);
}
