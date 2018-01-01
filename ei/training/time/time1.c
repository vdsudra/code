#include<stdio.h>
#include<time.h>
int main()
{
struct tm *local_time;
time_t ct;
char buffer[100];
ct=time(NULL);
local_time=localtime(&local_time);
fputs(asctime(local_time),stdout);
printf("\n%s\n",asctime(local_time));
printf("%A\n",local_time);
ct=time(NULL);
printf("\n%ld\n",ct);
return 0;
}
