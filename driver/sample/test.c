#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char buff[100] = {0};
	int i = 0;

	int fp = open("/dev/myDev", O_RDWR);
	if(fp < 0){
		printf("Error to open /dev/myDev\n");
		perror("Error");
		printf("Aborting...\n");
		return -1;
	}
	int run = 1;
	while(run){
		scanf("%s", buff);
		if(0 == strcmp("q", buff))
			break;
		i = write(fp, buff, sizeof(buff));

		printf("Wrote ret %d: %s\n", i,buff);
		//printf("off:%d\n",(int) lseek( fp, 0, SEEK_CUR )) ;
		i = read(fp, &buff, 100);
		printf("Read ret %d: %s\n",i, buff);
		//printf("off:%d\n",(int) lseek( fp, 0, SEEK_CUR )) ;
	}
	close(fp);
	return 0;
}
