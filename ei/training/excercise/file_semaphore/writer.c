#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/mman.h>
#include<string.h>
int main()
{
int fd_wr,s_val;
char buffer[100];
sem_t *my_sem=0;
fd_wr=open("message.txt",O_CREAT | O_TRUNC |O_WRONLY,0644);
if(fd_wr==-1)
	{
	perror("Error opening file for writing");
	exit(EXIT_FAILURE);
	}  

my_sem = sem_open("semaphore",O_CREAT, 0644,1); 
if(!my_sem)
	{
	fprintf(stderr,"semaphore creation fail");
	exit(EXIT_FAILURE);
	}

while(strncmp(buffer,"end",3)!=0)
	{
	
	sem_getvalue(my_sem,&s_val);
	printf("Value of semaphore before wait:- %d\n",s_val);
	sleep(4);
	sem_wait(my_sem);
	sem_getvalue(my_sem,&s_val);
	printf("Enter data to be write(1):  ");
	fgets(buffer,sizeof(buffer),stdin);
	write(fd_wr,buffer,strlen(buffer));
	lseek(fd_wr,0,SEEK_SET);
	sleep(1);
	sem_post(my_sem);
	sem_getvalue(my_sem,&s_val);
	printf("Value of semaphore after post:- %d\n",s_val);	
	}
sem_close(my_sem);
sem_unlink("semaphore");
sem_destroy(my_sem);
close(fd_wr);
exit(EXIT_SUCCESS);

}
