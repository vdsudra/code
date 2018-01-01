#include <signal.h>
#include <stdio.h>
static void sigHandler(int sig)
{
	printf("Ouch!\n");
	return ;
}
int main(int argc, char *argv[])
{
	int j;
	if (signal(SIGINT, sigHandler) == SIG_ERR)
		exit(0);
	for (j = 0; ; j++) {
		printf("%d\n", j);
		sleep(3);
	}
}
