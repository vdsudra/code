#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
FILE *read_fp;
char buffer[BUFSIZ/10 +1];
int char_read;
memset(buffer,'\0',sizeof(buffer));
read_fp=popen("ps -x","r");
if(read_fp != NULL){
char_read=fread(buffer,sizeof(char),sizeof(buffer),read_fp);
if(char_read > 0){
buffer[char_read-1]='\0';
printf("Reading %d:-\n %s\n",BUFSIZ/10,buffer);
//char_read=fread(buffer,sizeof(char),sizeof(buffer),read_fp);
}
pclose(read_fp);
exit(EXIT_SUCCESS);
}
exit(EXIT_FAILURE);
}
