#include<string.h>
#include<stdio.h>
int main()
{
	char *p;
	int i;
	p=strchr("This is my string",'m');
	printf("%s\n",p);
	char s[]="Is it not is so, why is like that is";
	p=strtok(s,"is");
	while(s!=NULL)
	{
		p=strtok(s,"is");
		printf("%s\n",s);
	}
}
