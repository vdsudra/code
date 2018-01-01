/*************************************************************************************************/
//	echo filemane 
//  or	echo "data" filename
//	ex: echo /home/ei/abc  --to create file named abc
//	ex: echo "xyz" /home/ei/abc  --copy data "xyz" into file abc
//	ex: echo "xyz" /home//ei/abc  --copy data "xyz" into file abc
//	//	ex: echo "xyz" /home//eo/abc  --error
/************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int echo(int,char *[]);
int main(int argc,char *argv[])
{
	int status=1;
	if(argc <2 || argc >3)
	{
		printf("Invalid Arguments");
		status=-1;
	}
	else
	{
		echo(argc,argv);
	}
	return status;
}

/*******************************************************************************/
/*! \fn        echo(int count, char *arg_v[])
 *
 *   \brief    create file , append to file if exist
 *
 *   \param    [IN]  - count - number of arguments
 *   \param    [IN]  - *arg_v[] - store the arguments
 *
 *   \return   int
 */
/*******************************************************************************/
int echo(int count,char *arg_v[])
{
	int fd;
	int status=1;
	char buffer[1024];
	switch(count)
	{
		//create a new file with default permission
		case 2:
			{
				fd = open(arg_v[1],O_CREAT,0664);
				if(fd < 0)
				{
					printf("Error in creating the file\n");
					status=-1;
					break;			
				}
				close(fd);
				break;
			}
		// create a file with user define permission

		case 3:
			{	
				memset(buffer,'\0',1024);
				strcpy(buffer,arg_v[1]);
				strcat(buffer,"\n");
				//open file to write at the end of file				
				fd = open(arg_v[2],O_WRONLY | O_APPEND);
				if(fd < 0)
				{
					printf("Error to open file\n");
					status =-1;
					break;
				}
				//write data into file
				int res=write(fd,buffer,strlen(buffer));
				if(res == -1)
				{
					printf("Error in writing\n");
					status=-1;
					break;	
				}
				close(fd);
				break;
			}

		default:
			{
				printf("Invalid Arguments\n");
				status=-1;
				break;	
			}
	}
	return status;
}

