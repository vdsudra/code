#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
int CheckDir(char *src,char *dst);
void RemoveDir(char *dest);
int CopyDir(char *src,char *dst);
int MakeDir(char *dst_dir);
int CopyFile(char *src ,char *dst);
int main(int argc,char *argv[])
{
	int status=0;
	char *src,*dest;
	do
	{
		if(argc <3 || argc >4)
		{
			printf("Invalid number of arguments\n");
			status=1;		
			break;
		}
		src=argv[1];
		dest=argv[2];
		if((status=CheckDir(src,dest))!=0)
		{
			printf("Copy Unsuccessful\n");
			break;
		}
		if((status=CopyDir(src,dest))!=0)
		{
			RemoveDir(dest);
			printf("Copy Unsuccessful\n");
			break;
		}
		printf("Copy Successful\n");
	}while(0);
	return status;
}

int CheckDir(char *src,char *dst)
{
	int status=0;
	DIR *dir;
	do
	{
		dir=opendir(src);
		if(ENOENT == errno)
		{
			perror("Error");
			status= 1;
			break;
		}
		else if(dir==NULL)
		{
			perror("Error");
			status= 1;
			break;
		}
		dir=opendir(dst);
		if(ENOENT != errno)
		{
			printf("directory Already Exist\n");
			status= 1;
			break;
		}
	}
	while(0);
	return status;
}

int CopyDir(char *src,char *dst)
{
	int status=0;	
	struct dirent *dir_path;
	char temp_dir[50]={0};
	char temp_path[1000]={0};
	char temp_dest_path[1000]={0};
	struct stat statbuf;
	DIR *dirp_source;
	do
	{
		if((MakeDir(dst))!=0)
		{
			status=1;
			break;
		}	
		if((dirp_source=opendir(src))==NULL)
		{
			status =1;
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
			snprintf(temp_path,100,"%s/%s",src,temp_dir);
			snprintf(temp_dest_path,100,"%s/%s",dst,temp_dir);	
			stat(temp_path, &statbuf);
			if(S_ISDIR(statbuf.st_mode))
			{
				if(0!=(status=CopyDir(temp_path,temp_dest_path)))
					break;
			}
			else
			{
				if(0!=(status=CopyFile(temp_path,temp_dest_path)))
					break;
			}
		}
	}while(0);
	return status;
}
int MakeDir(char *dst_dir)
{
	int status=0;
	if((mkdir(dst_dir, 0777)) == -1)
	{
		status = 1;
		if(errno == EACCES)
		{
			fprintf(stderr, "Permission Denied\n");
		}
		else if(errno == EEXIST)
		{
			fprintf(stderr, "Directory Already Exist\n");
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

int CopyFile(char *src ,char *dst)
{
	int status=0;
	FILE *rd=NULL;
	FILE *wr=NULL;
	char ch=0;
	do
	{
		if((rd=fopen(src,"r"))==NULL)
		{
			perror("Error");
			status = 1;
			break;
		}
		if((wr=fopen(dst,"w"))==NULL)
		{
			perror("Error");
			status = 1;
			fclose(rd);
			break;
		}
		while(( ch = fgetc(rd) ) != EOF )
		{
			fputc(ch,wr);
		}
		fclose(rd);
		fclose(wr);
	}while(0);
	return status;
}


void RemoveDir(char *dest)
{
	struct dirent *dir_path;
	char temp_dir[50]={0};
	char temp_path[1000]={0};
	struct stat statbuf;
	DIR *dirp_source;
	if((dirp_source=opendir(dest))==NULL)
	{
		perror("Error");
		return;
	}
	while(1)
	{
		dir_path=readdir(dirp_source);
		if(dir_path==NULL)
		{
			break;
		}
		else if((strcmp(dir_path->d_name,"..")==0) || (strcmp(dir_path->d_name,".")==0))
			continue;
		snprintf(temp_dir,100,"%s",dir_path->d_name);
		snprintf(temp_path,100,"%s/%s",dest,temp_dir);
		stat(temp_path, &statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			RemoveDir(temp_path);
		}
		else
		{
			remove(temp_path);
		}
	}
	remove(dest);
}
