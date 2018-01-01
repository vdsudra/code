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
    char buffer[50];
    sem_t *my_sem;
    char *map_p;
    fd_wr=open("msg",O_CREAT|O_RDWR, 0666);
    if(fd_wr==-1)
    {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }  

    ftruncate(fd_wr,4096);
    map_p=(char *)mmap(NULL, 4096 ,PROT_READ | PROT_WRITE, MAP_SHARED, fd_wr, 0);
    if(map_p== MAP_FAILED) 
    {
        perror ("mmap failure");
        exit(0);
    }

    printf("Pointer:%p\n",map_p);
    my_sem=sem_open("semaphore",O_CREAT, 0644,1); 
    if(my_sem==SEM_FAILED)
    {
        fprintf(stderr,"semaphore creation fail");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore Id:%d\n",(int)my_sem);
    while(strncmp(buffer,"end",3)!=0)
    {
        sem_getvalue(my_sem,&s_val);
        printf("Value of semaphore before wait:- %d\n",s_val);
        sleep(2);
        sem_wait(my_sem);
        sem_getvalue(my_sem,&s_val);
        printf("Value of semaphore after wait:- %d\n",s_val);
        printf("Enter data to be write(2):");
        fgets(buffer,sizeof(buffer),stdin);
        strcpy(map_p,buffer);
        //sprintf(map_p,"%s","hello.... ");
        //memcpy(map_p,buffer,strlen(buffer));	
        sleep(1);
        sem_post(my_sem);
    }
    sem_close(my_sem);
    sem_unlink("semaphore");
    sem_destroy(my_sem);
    munmap(map_p,4096);
    close(fd_wr);
    exit(EXIT_SUCCESS);

}
