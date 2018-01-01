#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/shm.h>
#include<string.h>
#include<fcntl.h>
#include<time.h>
int main()
{
int shm_id,amt;
char *data;
time_t start,stop;
double time_used;

printf("Enter amount of memory to be shared:\n");
scanf("%d",&amt);
char buf[amt];
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
memset(data,'A',amt);	
stop=clock();
time_used=((double)(stop-start));
printf("clock consumed=%f\n",time_used);
time_used=((double)(stop-start))/ CLOCKS_PER_SEC;
printf("Time consumed=%f\n",time_used);

if(shmdt(data)==-1)
	{
	printf("shmdt failed\n");
	exit(0);
	}

exit(1);
}
