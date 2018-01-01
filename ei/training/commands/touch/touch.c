#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int touch();
int main(int argc,char *argv[])  
{
if(argc < 2) 
	{
	printf("Invalid arguments\n");
	return 0;
	}
touch();
return 0;
}

int touch(int argc,char *argv[])
{
int i,filedesc;
for(i=1;i<argc;i++)
	{
	filedesc = open(argv[i],O_APPEND | O_CREAT | O_RDWR,0644 );
	if(filedesc < 0)
		{
		printf("Error in creating the file\n");
		return 1;
		}
	}
return 0;
}
