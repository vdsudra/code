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
//int *ptr_wr;
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
/*ptr_wr=mmap(0,100,PROT_WRITE,MAP_SHARED,fd_wr,0);
if(ptr_wr==MAP_FAILED)
	{
	close(fd_wr);
	perror("Error mmapping the file");
	exit(EXIT_FAILURE);
	}*/

while(strncmp(buffer,"end",3)!=0)
	{
	sem_getvalue(my_sem,&s_val);
	//printf("Value of semaphore before wait:- %d\n",s_val);
	sleep(2);
	sem_wait(my_sem);
	sem_getvalue(my_sem,&s_val);
	printf("Value of semaphore after wait:- %d\n",s_val);
	printf("Enter data to be write(2):  ");
	fgets(buffer,sizeof(buffer),stdin);
	write(fd_wr,buffer,strlen(buffer));
	sleep(2);	
	lseek(fd_wr,0,SEEK_SET);
	sem_post(my_sem);
	sem_getvalue(my_sem,&s_val);
	printf("Value of semaphore after post:- %d\n",s_val);
	}

//munmap(ptr_wr,100);
sem_close(my_sem);
sem_unlink("semaphore");
sem_destroy(my_sem);
close(fd_wr);
exit(EXIT_SUCCESS);

}
