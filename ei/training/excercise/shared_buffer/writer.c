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
struct sh_data{
char name[10];
char addr[5];
unsigned int no;
}*mydata;
char *data;
//char buffer[100];

printf("\n");
printf("\n");
shm_id=shmget(123,sizeof(sh_data),IPC_CREAT|0644);
if(shm_id==-1)
	{
	printf("semget Failed\n");
	exit(1);
	}
printf("id=%d\n",shm_id);
data=shmat(shm_id,0,0);
if(data==(char *)-1)
	{
	printf("semat Failed\n");
	exit(1);
	}

while(strncmp("end",data,3)!=0)
	{
	
	printf("Enter data to be write: ");
	fgets(data,sizeof(data),stdin);
	//strncpy(data,buffer,sizeof(buffer));
	
	sleep(2);
	}
if(shmdt(data)==-1)
	{
	printf("shmdt failed\n");
	exit(1);
	}
if(shmctl(shm_id,IPC_RMID,0)==-1)
{
	printf("shmctl failed\n");
	exit(1);
}
exit(0);
}
