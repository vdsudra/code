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
memset(buffer,'A',sizeof(buffer));
if(pipe(file_pipes)==0)
{
fork_result=fork();
if(fork_result==-1){
fprintf(stderr,"Fork Fail");
exit(EXIT_FAILURE);}
if(fork_result==0){
sprrintf(buffer,"%d",file_pipes[0]);
(void)exel("pipe4","pipe4",buffer,(char *)0);
exit(EXIT_FAILURE);
}
else{

