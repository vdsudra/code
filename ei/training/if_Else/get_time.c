#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h> 
int main()
{
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
	strftime(buf1, 50, "%x_%H",loc_time);
	strftime(buf,50, "%M",loc_time);
	m=atoi(buf);
	printf("%s %d",buf1,m);
	wr=fopen("datafile","w");
	if(wr==NULL)
		return 0;
	fprintf(wr,"%s %d",buf1,m);
	fclose(wr);
	sleep(5);
	printf("+++++\n");		
	rd=fopen("datafile","r");
	if(rd==NULL)
	{
		return 0;
	}
	fscanf(rd,"%s %d",buf,&h);
	printf("%s %d\n",buf,h);
	fclose(rd);
	return 0;
}
