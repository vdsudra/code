#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
void Remove_Dir(char *dest); 
int main()
{
	int i=0;
	printf("1");
	Remove_Dir("mkdir");
}

void Remove_Dir(char *dest)
{

        struct dirent *dir_path;
        char temp_dir[50]={0};
        char temp_path[1000]={0};
        struct stat statbuf;
        DIR *dirp_source;
		printf("1");
        if((dirp_source=opendir(dest))==NULL)
        {
		printf("1");
                perror("Error");
		printf("2");
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
                stat(temp_dir, &statbuf);
                if(S_ISDIR(statbuf.st_mode))
                {
                        Remove_Dir(temp_path);
                }
                else
                {
		printf("9");
		remove(temp_path);
                }
        }
}

