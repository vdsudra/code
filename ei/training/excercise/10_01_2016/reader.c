#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/mman.h>
#include<string.h>
int main()
{
    int fd_rd;
    sem_t *my_sem=0;
    char buffer[100];
    char *map_p;
    fd_rd=open("msg",O_RDWR|O_CREAT);
    if(fd_rd==-1)
    {
        perror("Error opening file");
        exit(0);
    }
    ftruncate(fd_rd,4096);

    map_p=mmap(NULL,4096,PROT_READ,MAP_SHARED,fd_rd,0);
    if(map_p==(char *)-1) 
    {
        perror ("mmap failure");
        exit(0);
    }

    printf("Adderess:%p\n",map_p);
    my_sem=sem_open("semaphore",O_CREAT, 0644,1); 
    if(!my_sem)
    {
        fprintf(stderr,"semaphore creation fail");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore Id:%d\n",(int)my_sem);
    while(strncmp("end",buffer,3)!=0)
    {
        strcpy(buffer,(char *)map_p);
        printf("You Wrote : %s\n",buffer);
        sleep(1);
    }

    sem_close(my_sem);
    sem_unlink("semaphore");
    close(fd_rd);
    sem_destroy(my_sem);
    munmap(map_p,4096);
    exit(EXIT_SUCCESS);

}
