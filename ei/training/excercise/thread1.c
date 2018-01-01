#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
void *thread_func(void *arg);
char message[]="Hello....";
int main()
{
int res;
pthread_t thread_a;
void *thread_result;
if((pthread_create(&thread_a,NULL,thread_func,(void *)message))!=0)
	{
	perror("Thread creation fail");
	exit(EXIT_FAILURE);
	}
printf("Waiting to finish\n");
if((pthread_join(thread_a,&thread_result))!=0)
	{
	perror("Thread joining fail");
	exit(EXIT_FAILURE);
	}
printf("Thread joined,it returns %s\n",(char *)thread_result);
printf("Message is now %s\n",message);
exit(EXIT_SUCCESS);
}

void *thread_func(void *arg)
{
printf("Thread function is running and argument is %s\n",(char *)arg);
sleep(3);
strcpy(message,"Bye..");
pthread_exit("Thank you...");
}

