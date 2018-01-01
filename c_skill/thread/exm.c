#include <pthread.h>
#include <stdio.h>

struct demo{
int time;
char *str;
};
void *threadFunc(void *arg)
{
	char *str;
	int i = 0;

	struct demo *d=(struct demo *)arg;

	while(i < 10 )
	{
		//usleep.(1);
		sleep(d->time);
		printf("%s : %d\n",d->str,i);
		++i;
	}

	return NULL;
}

int main(void)
{
	pthread_t t1,t2,t3;	// this is our thread identifier
	int i = 0;
	struct demo d={1,"First"};
	struct demo d1={2,"Second"};

	pthread_create(&t1,NULL,threadFunc,&d);
	pthread_create(&t2,NULL,threadFunc,&d1);

	while(i < 10)
	{
		//usleep(1);
		sleep(1);
		printf("main is running...  %d\n",i);
		++i;
	}

	printf("main waiting for thread to terminate...\n");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;
																													}
