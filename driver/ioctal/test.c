#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "ioctl_h.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>
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
	unsigned int size;
	while(run){
		ioctl(fp, GET_SIZE, &size);
		printf("Size:%u\n", size);
		scanf("%s", buff);
		if(0 == strcmp("q", buff))
			break;
		i = write(fp, buff, sizeof(buff));

//		printf("Wrote ret %d: %s\n", i,buff);
		//printf("off:%d\n",(int) lseek( fp, 0, SEEK_CUR )) ;
		size = 2048;
		ioctl(fp, SET_SIZE, &size);
		ioctl(fp, GET_SIZE, &size);
		printf("Size after set:%u\n", size);
//		i = read(fp, &buff, 100);
		printf("Read ret %d: %s\n",i, buff);
		//printf("off:%d\n",(int) lseek( fp, 0, SEEK_CUR )) ;
		ioctl(fp, FILL_ZERO, &size);
		i = read(fp, &buff, 100);
		printf("Read after 0 ret %d: %s\n",i, buff);
		char ch = 'z';
		ioctl(fp, FILL_CHAR, &ch);
		i = read(fp, &buff, 100);
		printf("Read after set 'x' ret %d: %s\n",i, buff);

		run =0;
	}
	close(fp);
	return 0;
}
