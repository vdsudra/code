#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/shm.h>
#include<string.h>
#include<fcntl.h>
int main()
{
int shm_id;
sem_t *sem_id;
char *data;
//char buffer[100];

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
sem_id=sem_open("mysem",O_CREAT, 0644,1); 
if(sem_id==SEM_FAILED)
	{
	fprintf(stderr,"semaphore creation fail");
	exit(EXIT_FAILURE);
	}


while(strncmp("end",data,3)!=0)
	{
	sem_wait(sem_id);
	printf("Enter data to be write: ");
	fgets(data,sizeof(data),stdin);
	//strncpy(data,buffer,sizeof(buffer));
	sem_post(sem_id);
	sleep(2);
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
sem_close(sem_id);
sem_unlink("mysem");
sem_destroy(sem_id);
exit(1);
}
