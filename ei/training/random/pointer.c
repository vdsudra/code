#include<stdio.h>
int main(int argc ,char *argv[])
{
	int i=0;
	for(i=0;i<argc;i++)
	{
		printf("%s%s",*++argv,(argc > 1) ? " " : "");

	}

	printf("\n");
	char huge * p=(char huge*)0x12340001;
	char huge* p1=(char huge*)0x12300041;
	if(p==p1)
		printf("same");
	else
		printf("different");	
	printf("Size:%d\n",fsize("cmd_arg.c"));
	return 0;

}
