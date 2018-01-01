#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<semaphore.h>
void *thread_func(void *arg);
sem_t binary_sem;
char buffer[1024];
int main()
{
int res;
pthread_t thread_a;
void *thread_result;
res=sem_init(&binary_sem,0,0);
if (res != 0) 
	{
	perror("Semaphore initialization failed");
	exit(EXIT_FAILURE);
	}
res=pthread_create(&thread_a,NULL,thread_func,NULL);
if(res!=0)
	{
	perror("Thread creation failed");
	exit(EXIT_FAILURE);
	}
printf("Enter some text. enter end to finish\n");
while(strncmp("end",buffer,3)!=0)
	{
	if(strncmp(buffer,"fast",4)==0)
		{
		sem_post(&binary_sem);
		strcpy(buffer,"hii..");
		}
	fgets(buffer,1024,stdin);
	sem_post(&binary_sem);
	}
printf("Waitinig for thread to finish..\n");
res=pthread_join(thread_a,&thread_result);
if(res!=0)
	{
	perror("Thread joining fail");
	exit(EXIT_FAILURE);
	}
printf("Thread joined..\n");
sem_destroy(&binary_sem);
exit(EXIT_SUCCESS);
}

void *thread_func(void *arg)
{
sem_wait(&binary_sem);
while(strncmp("end",buffer,3)!=0)
	{
	printf("You entered %d characters\n",strlen(buffer)-1);
	sem_wait(&binary_sem);
	}
pthread_exit("Thank you...");
}
