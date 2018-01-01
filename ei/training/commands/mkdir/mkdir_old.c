/*************************************************************************************************/
//	mkdir  filemane  or path
//	ex: mkdir abc  --to create  named abc
//	ex: echo "xyz" /home/ei/abc  --copy data "xyz" into file abc
//	ex: echo "xyz" /home//ei/abc  --copy data "xyz" into file abc
//	//	ex: echo "xyz" /home//eo/abc  --error
/************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
int mk_dir(char *);
int main(int argc, char *argv[])
{
int status=1;
if(argc != 2)
{
	printf("Invalid arguments\n");
	status=-1;
}
else
{
status=mk_dir(argv[1]);
}
return status;
}
/*******************************************************************************/
/*! \fn        mk_dir(char *dir_name)
 *
 *   \brief    create file , append to file if exist
 *
 *   \param    [IN]  - *dir_name - path name or directory name
 *  
 *   \return   int
 */
/*******************************************************************************/
int mk_dir(char *dir_name)
{
char temp_name[1024]="/";
char ch;
int i,result,len;
int status=1;
struct stat stbuf;
ch=dir_name[0];

switch(ch)
{
//create directory in given path
case '/':
{
	len=strlen(dir_name);
	for(i=1;i<=len;i++)
	{
		if(dir_name[i]!='/' && (i!=len))
		{
			temp_name[i]=dir_name[i];
			continue;	
		}
		//check for the directory if not exist then create
		if(stat(temp_name,&stbuf) == -1 )
		{
			result=mkdir(temp_name,S_IRWXU | S_IRGRP |  S_IXGRP | S_IROTH | S_IXOTH);
			temp_name[i]=dir_name[i];
			if(result==-1)
			{
				printf("Error to create directory\n");
				if(errno==ENOENT)
				{
					printf("Invalid path\n");
				}
				status=-1;		
			}
		status=1;
		}
		else
		{
			temp_name[i]=dir_name[i];
		}	
	}
break;	
}
//create directory in current path	
default:
{
	result=mkdir(dir_name,S_IRWXU | S_IRGRP |  S_IXGRP | S_IROTH | S_IXOTH);
	if(result ==-1)
	{
		printf("Error to create directory\n");
		status=-1;
	}
	break;

}
}
return status;	
}



