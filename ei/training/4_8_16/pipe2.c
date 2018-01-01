#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
    const char somedata[]="12345";
    int file_pipes[2];
    int processed_data;
    char buffer[100];
    pid_t fork_result;
    memset(buffer,0,sizeof(buffer));
    if(pipe(file_pipes)==0)
    {
        fork_result=fork();
        if(fork_result==-1){
            fprintf(stderr,"Fork Fail");
            exit(EXIT_FAILURE);}
        if(fork_result==0){
            sleep(3);
            processed_data=read(file_pipes[0],buffer,100);
            printf("Read %d Bytes %s\n",processed_data,buffer);
            exit(EXIT_SUCCESS);}
        else{
            sleep(1);
            processed_data=write(file_pipes[1],somedata,strlen(somedata));
            printf("Wrote %d Bytes\n",processed_data);}
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
