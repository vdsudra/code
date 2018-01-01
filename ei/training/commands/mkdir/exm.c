#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
int main(int argc, char *argv[])
{
struct dirent *dpath;
DIR *d_ptr;
char file_name[100];
struct stat stbuf;
char *dir_name;
dir_name=argv[1] ;

if(argc != 2)
{
printf("Invalid arguments\n");
return 0;
}

if((d_ptr=opendir(dir_name))==NULL)
	{
	return 0;
	}
while(1)
{
if((dpath=readdir(d_ptr))==NULL)
	{
	break;	
	}
/**********************************/
sprintf(file_name,"%s%s",dir_name,dpath->d_name) ;
if(stat(file_name,&stbuf) == -1 )
	{
	printf("Unable to stat file: %s\n",file_name) ;
	//continue ;
	}

if ((stbuf.st_mode & S_IFMT ) == S_IFDIR)
	{
	printf("This is directory: %s\n\n",dpath->d_name);
	printf("%s%s\n",dir_name,dpath->d_name);
	printf("\t\t\t%s\n",file_name);
	
	continue;
	}
/***********************************/
if (strcmp (dpath->d_name, "..") != 0 && strcmp (dpath->d_name, ".") != 0) 
	{
	printf("%s%s\n",dir_name,dpath->d_name);
	}
}

}




#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
char temp_name[1000]="/";
char *dir_name;
char ch;
dir_name=argv[1] ;
int i=1,result,len;
struct stat stbuf;
ch=dir_name[0];
if(argc != 2)
{
	printf("Invalid arguments\n");
	return 0;
}
switch(ch)
{
case '/':
{
	len=strlen(argv[1]);
	for(;i<=len;i++)
	{
		if(dir_name[i]!='/' && (i!=len))
		{
			temp_name[i]=dir_name[i];
			continue;	
		}
	
		if(stat(temp_name,&stbuf) == -1 )
		{
			result=mkdir(temp_name,S_IRWXU | S_IRWXG | S_IRWXO);
			temp_name[i]=dir_name[i];
			if(result==-1)
			{
				printf("Error to create directory\n");
				if(errno==ENOENT)
				{
					printf("Invalid path\n");
				}
			}
		}
		else
		{
			temp_name[i]=dir_name[i];
		}	
	}
break;	
}

default:
{
	result=mkdir(dir_name,S_IRWXU | S_IRWXG | S_IRWXO);
	if(result ==-1)
	{
		printf("Error to create directory\n");
		return 0;
	}
	break;

}
}
return 0;
}


