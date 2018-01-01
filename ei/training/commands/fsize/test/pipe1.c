#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int data_processed;
int file_pipes[2];
const char somedata[]="1234";
char buffer[1024];
memset(&buffer,'\0',sizeof(buffer));
if(pipe(file_pipes)==0){
data_processed=write(file_pipes[1],somedata,strlen(somedata));
printf("Wrote %d Bytes \n",data_processed);
data_processed=read(file_pipes[0],buffer,1024);
printf("Read %d Bytes\n",data_processed);
exit(EXIT_SUCCESS);
}
exit(EXIT_FAILURE);
}

