#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include"shm_com.h"
int main()
{
    void *shared_memory=(void *)0;
    struct shared_use_st *shared_stuff; 
    char buffer[TEXT_SZ];//buffer to take data from stdin
    int shmid;
    shmid=shmget((key_t)1234,sizeof(struct shared_use_st),0666 | IPC_CREAT);
    if(shmid==-1) 
    {
        fprintf(stderr,"shmget failed\n");
        exit(EXIT_FAILURE);
    }
    shared_memory=shmat(shmid,(void *)0, 0);
    if(shared_memory==(void *)-1) 
    {
        fprintf(stderr,"shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n",(int)shared_memory);
    shared_stuff=(struct shared_use_st *)shared_memory; // create share memory 
    while(running) 
    {
        while(shared_stuff->written_by_you==1 && running) // sleep for some time so reader become free
        {
            sleep(1);            
            //printf("waiting for client...\n");
        }
        printf("Enter some text(writer2):"); //if reader is free then ask to enter a data 
        fgets(buffer,BUFSIZ,stdin);//take data into buffer
        strncpy(shared_stuff->some_text,buffer,TEXT_SZ);//copy data to shared memory
        shared_stuff->written_by_you=1; // set flag to 1 so reader can read
        if (strncmp(buffer,"end",3)==0) 
        {
            running = 0; // to exit from loop
        }
    }
    if(shmdt(shared_memory)==-1) 
    {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

