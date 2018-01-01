#include <unistd.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#define RED   "\033[0;31m"
#define NONE   "\033[0m"

void CheckInFile(char *opt,char *pat, char *file);
int FindMatch(char *buff,char *pattern);
void CheckInFolder(char *opt,char *pat,char *fil);
int main(int argc,char *argv[])
{
	int status=0;
	char *pattern,*file,*option;
	do
	{
		if((argc < 3) || (argc >4))
		{
			printf("Invalid number of arguments\n");
			status=1;
			break;
		}
		pattern=argv[1];
		file=argv[2];
		if(pattern[0]=='-')
		{
option=argv[1];
			pattern=argv[2];
			file=argv[3];
			CheckInFolder(option,pattern,file);
		}
		else
		{
			CheckInFolder("0",pattern,file);

		}
	}while(0);
	return status;
}

void CheckInFile(char *opt,char *pat, char *file)
{
	FILE *fp=NULL;
	int len=0;
	int sum=0;
	int i;
	int status=1;
	DIR *dirp=NULL;
	char buffer[1024]={0};
	int line_no=1;
	do
	{
		if(NULL!=(dirp=opendir(file)))
		{
			printf("Not a file use -r\n");
			break;
		}

		fp=fopen(file,"r");
		if(fp==NULL)
		{
			break;
		}
		len=strlen(opt);
		for(i=0;i<len;i++)
		{
			sum=sum+opt[i];
		}
		while(!feof(fp))
		{
			if( fgets(buffer,1024, fp)!=NULL ) 
			{
				status=0;
				if((status=FindMatch(buffer,pat))==0)
				{
					if((len==153) || (len==263) ||(len==377) ||(len==267))
						printf("%s%s%s",RED,file,NONE);
					else if(len==269)
						printf("%s%d:%s%s:%s",RED,line_no,file,NONE,buffer);
				}
			}
			line_no++;
		}

	}while(0);
}

int FindMatch(char *buff,char *pattern)
{
	int p_len=0;
	int b_len=0;
	int i,j,k;
	int status=1;
	p_len=strlen(pattern);
	b_len=strlen(buff);
	for(i=0;i<b_len;i++)
	{
		for(j=0,k=i;j<p_len && k< b_len;j++,k++)
		{
			if(buff[k]!=pattern[j])
				break;
		}
		if(j==p_len)
		{
			status=0;
		}
	}
	return status;
}

void CheckInFolder(char *opt,char *pat,char *fil)
{
	struct dirent *dir_path;
	char temp_dir[50]={0};
	char temp_path[1000]={0};
	struct stat statbuf;
	DIR *dirp_source;
	do
	{
		if((dirp_source=opendir(fil))==NULL)
		{
			perror("Error");
			break;
		}
		while(1)
		{
			dir_path=readdir(dirp_source);
			if(dir_path==NULL)
			{
				break;
			}
			else if((strcmp(dir_path->d_name,"..")==0) || (strcmp(dir_path->d_name,".")==0) || (dir_path->d_name[0]=='.'))
				continue;
			snprintf(temp_dir,100,"%s",dir_path->d_name);
			snprintf(temp_path,100,"%s/%s",fil,temp_dir);
			stat(temp_path, &statbuf);
			if(S_ISDIR(statbuf.st_mode))
			{
				CheckInFolder(opt,pat,temp_path);
			}
			else 
			{
				CheckInFile(opt,pat,temp_path);
			}
		}
	}while(0);
}
