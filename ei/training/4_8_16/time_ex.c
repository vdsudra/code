#include<stdio.h>
#include<time.h>
void main()
{
time_t now;
struct tm *ts;
now=time(NULL);
ts=localtime(&now);
printf("\n%s\n",ts);
}
