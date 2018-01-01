#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
int main()
{
int shm_id=0;
char *data;
do
{
if((shm_id=shmget(123,100,0644 | IPC_CREAT ))==-1)
{
perror("shmget");
break;
}
if((data=shmat(shm_id,(void *)0,0))==(void *)-1)
{
perror("shmat");
break;
}
while(1)
{
printf("enter data");
scanf("%s",data);
sleep(1);
}
if(shmdt(data)==-1)
perror("shmdt");
}while(0);
}

