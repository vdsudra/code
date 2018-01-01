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
    //int running=1; //flag to print data on terminal upto the end statement
    void *shared_memory=(void *)0; //void pointer with null
    struct shared_use_st *shared_stuff; //shared memory pointer
    int shmid; 
    shmid=shmget((key_t)1234,sizeof(struct shared_use_st),0666 | IPC_CREAT);
    if(shmid==-1) 
    {
        fprintf(stderr,"shmget failed\n");
        exit(EXIT_FAILURE);
    }

    shared_memory=shmat(shmid,(void *)0,0); //give memory and returns the address of first byte
    if(shared_memory==(void *)-1) 
    {
        fprintf(stderr,"shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n",(int)shared_memory);

    shared_stuff=(struct shared_use_st *)shared_memory; 
    shared_stuff->written_by_you=0;//reset flag
    while(running) 
    {
        if(shared_stuff->written_by_you) 
        {
            printf("You wrote: %s", shared_stuff->some_text);
            sleep(1); //sleep for some amount of time
            shared_stuff->written_by_you=0;//reset the flag  after printing the data so writer can enter data
            if(strncmp(shared_stuff->some_text,"end",3)==0)
            {
                running=0; //To terminate the loop
            }
        }
    }

    if(shmdt(shared_memory)==-1) //detche the shared memory from process
    {
        fprintf(stderr,"shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    if(shmctl(shmid,IPC_RMID,0)==-1) //delete the shared memory
    {
        fprintf(stderr,"shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
