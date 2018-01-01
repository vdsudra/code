/*************************************************************************************************/
//	mkdir filemane or path 
//  	mkdir filemane or path permission  
//	ex: mkdir abc  --create directory abc in current path
//	ex: mkdir /home/ei/abc  --create directory abc in given path 
//	ex: mkdir abc 0777 --create directory abc in current path with permission 0777
//	ex: mkdir /home/ei/abc 0744 --create directory abc in given path with 0744 permission 
//	ex: mkdir /home/ei/abc 0744 a5g --Error to create directory
/************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int mkdirp(char *,int);
int Create_Dir(char *, int);

int main(int argc, char *argv[])
{
	int per;
	int status=1;
	if(argc <2)
	{
		printf("Invalid arguments\n");
		status=-1;
	}
	else
	{
		switch(argc)
		{
			case 2:
				{
					mkdirp(argv[1],0755);
					break;
				}
			case 3:
				{
					sscanf(argv[2], "%o", &per);
					mkdirp(argv[1],per);
					break;
				}

			default:
				{
					printf("Invalid argument type");
					status=-1;
				}
		}
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
int mkdirp(char *dir_name,int per)
{
	//create directory in given path
	char temp_name[1000]="/";
	char ch;
	int i, len;
	struct stat stbuf;
	int status=1;
	ch=dir_name[0];

	switch(ch)
	{
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
						//make directory 
						if((Create_Dir(temp_name,per)) == 1)
						{
							status=-1;
							break;
						}
						temp_name[i]=dir_name[i];
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
				//make directory 
				if((Create_Dir(dir_name,per)) == -1)
				{
					status=-1;
					break;
				}

			}
	}

	return status;	
}

/*******************************************************************************/
/*! \fn        Create_Dir(char *source, int mode)
 *
 *   \brief    Create New Directory with given permission
 *
 *   \param    [IN]  - source - Path of Input file
 *   \param    [IN]  - Mode - Permission of New Directory
 *
 *   \return   int
 */
/*******************************************************************************/
int Create_Dir(char *source, int mode)
{
	int status=1;

	if((mkdir(source, mode)) == -1)
	{
		status = -1;

		if(errno == EACCES)
		{
			fprintf(stderr, "Permission Denied\n");
		}

		else if(errno == EEXIST)
		{
			fprintf(stderr, "Directory Alread Exist\n");
		}

		else if(errno == ENAMETOOLONG)
		{
			fprintf(stderr, "Path Length Limit Exceeds\n");
		}

		else
		{
			fprintf(stderr, "Failed to Create\n");
		}

	}

	return status;
}
