#include<stdio.h>
#include<pthread.h>
#include<string.h>
void *fun1(void *);
struct tharg
{
	int no;
	char buffer[1024];
};

int main()
{
	pthread_t th1,th2;
	struct tharg arg1;
	strcpy(arg1.buffer,"First Argument");
	arg1.no=100;
	if((pthread_create(&th1,NULL,&fun1,&arg1))!=0)
	{
		printf("Thread Creation failed\n");
		return 0;
	}
	pthread_join(th1,NULL);
}

void *fun1(void *arg)
{
	struct tharg *a;
	a=(struct tharg *)arg;
	printf("Function Called\n");
	printf("%s\n",a->buffer);
	printf("%d\n",a->no);
	return 0;
}
