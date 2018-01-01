#include <stdio.h>
#include <dirent.h>
#include<string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
DIR *dir;
char *d_name;
char *dir_name="/home/einfochips/";
char buffer[10];
struct dirent *entry;
if(argc !=2)
	{
	printf("Invalid arguments\n");
	return 0;	
	}
strcpy(buffer,argv[1]);
//dir = opendir(dir_name);

while(1)
{
	dir = opendir(dir_name);
	entry = readdir(dir);
	if (! entry) 
	{	
		break;
	}
	d_name = entry->d_name;
	printf ("%s/%s\n", dir_name, d_name);
	
	if (entry->d_type & DT_DIR) 
	{
		if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0) 
		{
			int path_length;
			char path[PATH_MAX];
			path_length = snprintf (path, PATH_MAX,"%s/%s", dir_name, d_name);
			printf ("%s\n", path);
			if (path_length >= PATH_MAX) 
			{
				fprintf (stderr, "Path length has got too long.\n");
				exit (EXIT_FAILURE);
			}
			strcpy(dir_name,path);
		}
	}
}
/*while((entry = readdir(dir)) != NULL) 
{
//printf("%s\n", entry->d_name);
//if(strncmp(entry->d_name,argv[2],sizeof(*argv[2]))==0)
if(strncmp(entry->d_name,buffer,sizeof(buffer))==0)
{
printf("\n\t%s\n",entry->d_name);
}
printf("1\n");
}*/
closedir(dir);
return 0;
}
