#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h> 
int main()
{
	int h1,m1,day1;
	FILE *rd=NULL;
	FILE *wr=NULL;
	char buf[50];
	char buf1[50];
	int h,m,day;
	time_t curtime;
	struct tm *loc_time;
	printf("Hello\n");	
	curtime = time(NULL);
	loc_time = localtime(&curtime);
	strftime(buf, 50,"%x-%M",loc_time);
	printf("%s",buf);
	wr=fopen("datafile","w");
	if(wr==NULL)
		return 0;
	fprintf(wr,"%s",buf);
	fclose(wr);
	while(1)
	{
		sleep(10);
		curtime = time(NULL);
		loc_time = localtime(&curtime);
		strftime(buf, 50,"%x-%M",loc_time);
		rd=fopen("datafile","r");
		if(rd==NULL)
		{
			return 0;
		}
		fscanf(rd,"%s",buf1);
		fclose(rd);
if(0==strcmp(buf1,buf))
{

	printf("Hello\n");	
}
else
{

	printf("++++\n");	
}
	}
	return 0;
}
