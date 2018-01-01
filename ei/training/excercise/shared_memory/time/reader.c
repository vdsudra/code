#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h> 
#include<sys/shm.h>
#include<string.h>
#include<time.h>
int main()
{
time_t start,stop;
double time_used;
int shm_id,amt;
char *data;
printf("Enter amount of memory to be read:\n");
scanf("%d",&amt);

shm_id=shmget(123,amt,IPC_CREAT|0644);
if(shm_id==-1)
	{
	printf("semget Failed\n");
	exit(0);
	}
printf("id=%d\n",shm_id);
data=(char *)shmat(shm_id,(void *)0,0);
if(data==(char *)-1)
	{
	printf("semat Failed\n");
	exit(0);
	}

start=clock();
printf("You Wrote : %s\n",data);
stop=clock();
time_used=stop-start;
time_used=((double)(stop-start));
printf("clock consumed=%f\n",time_used);
time_used=((double)(stop-start))/ CLOCKS_PER_SEC;
printf("Time consumed=%f\n",time_used);


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
