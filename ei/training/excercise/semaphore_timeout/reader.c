#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/mman.h>
#include<string.h>
#include<time.h>
int main()
{
int fd_rd;
sem_t *my_sem=0;
char buffer[100];
fd_rd=open("message.txt",O_RDONLY);

if(fd_rd==-1)
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
while(strncmp("end",buffer,3)!=0)
	{
	lseek(fd_rd,0,SEEK_SET);
	read(fd_rd,buffer,100);
	printf("You Wrote : %s\n",buffer);
	sleep(1);
	}

sem_close(my_sem);
sem_unlink("semaphore");
close(fd_rd);
sem_destroy(my_sem);
exit(EXIT_SUCCESS);

}
