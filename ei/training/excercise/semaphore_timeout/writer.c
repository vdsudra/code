#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<semaphore.h>
#include<string.h>
#include<time.h>
#include<errno.h>
int main()
{
int fd_wr,t;
char buffer[100];
struct timespec t_out;
sem_t *my_sem=0;
fd_wr=open("message.txt",O_CREAT | O_TRUNC |O_WRONLY,0644);
if(fd_wr==-1)
	{
	perror("Error opening file for writing");
	exit(EXIT_FAILURE);
	}  

my_sem=sem_open("semaphore",O_CREAT, 0644,1); 
if(!my_sem)
	{
	fprintf(stderr,"semaphore creation fail");
	exit(EXIT_FAILURE);
	}
if(clock_gettime(CLOCK_REALTIME,&t_out)==-1)
	{
	printf("Get Time failed\n");
	}
t_out.tv_sec=2; 


while(strncmp(buffer,"end",3)!=0)
	{
	while((t=sem_timedwait(my_sem, &t_out))==-1 && errno==EINTR)
		{
		continue;
		}   
	if(t==-1 && errno==ETIMEDOUT) 
		{
		printf("sem_timedwait() timed out\n");
		printf("Please Waiting for semaphore......\n");
		//sleep(1);
		}
	else
		{
		printf("sem_timedwait() succeeded and obtained semaphore lock\n");
		printf("Enter data to be write(1):  ");
		fgets(buffer,sizeof(buffer),stdin);
		write(fd_wr,buffer,strlen(buffer));
		lseek(fd_wr,0,SEEK_SET);
		sleep(1);
		sem_post(my_sem);
		sleep(3);
		}
	}
sem_close(my_sem);
sem_unlink("semaphore");
sem_destroy(my_sem);
close(fd_wr);
exit(EXIT_SUCCESS);

}
