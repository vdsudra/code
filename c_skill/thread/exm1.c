#include <pthread.h>
#include <stdio.h>
#include<pthread.h>

pthread_mutex_t lock;
int count = 1000;
void *threadFunc(void *arg)
{
	char *str= (char *)arg;

		pthread_mutex_lock(&lock);
	if(count > 0 )
	{
		//usleep.(1);
		sleep(1);
		//printf("%s : %d\n",str,count);
		count=count - 1000;
		//printf("Incremented by %s\n",str);
		printf("Decremented count %s  %d\n",str,count);
	}
	else{
		count+=1000;
		printf("Incremented count by %s  %d\n",str, count);
	}
		pthread_mutex_unlock(&lock);

	return NULL;
}

int main(void)
{
	pthread_t t1,t2,t3;	// this is our thread identifier

	pthread_create(&t1,NULL,threadFunc,"Thread 1");
	pthread_create(&t2,NULL,threadFunc,"Thread 2");

	printf("main waiting for thread to terminate...\n");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;
																													}
