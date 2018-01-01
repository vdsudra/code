#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	int i=1000;
	int j=0;
	pid_t fork_result;
	fork_result=fork();
	
	if(fork_result==-1){
		fprintf(stderr,"Fork Fail");
		exit(EXIT_FAILURE);}
	
	if(fork_result==0){
		printf("CHILD | Add J: %p Add I:%p\n ",&j,&i);
		
		j = 10, i = 20;
		printf("CHILD | J = %d, I = %d\n", j,i);


		for(j=0;j<10;j++)
		{
			printf("Child Process is running");
			printf("J:%d I:%d\n",j,i);
			sleep(1);
		}

		getchar();
	}
	
	else {

		printf("PARENT | Add J: %p Add I:%p\n ",&j,&i);
		
		j=30, i=40;
		printf("PARENT | J = %d, I = %d\n", j,i);
		for(j=0;j<10;j++,i=i-100)
		{
			printf("Parent Process is running");
			printf("J:%d I:%d\n",j,i);
			sleep(1);
		}
		getchar();
	}
}
