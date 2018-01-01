#include<stdio.h>
#include<errno.h>
#include<string.h>
struct mystruct
{
	int i;
	char name[100];
	void *p;
};

void my_fun(void *);

int main()
{
	struct mystruct mem1;
	strcpy(mem1.name,"hi");
	mem1.i=10;
	mem1.p=&mem1;
//	mem1.p=(struct mystruct *)&mem1;
	printf("Hello\n");
	my_fun(&mem1);
	return 0;
}

void my_fun(void *ptr)
{
	struct mystruct *mptr;
	mptr=(struct mystruct *)ptr;
//	printf("%s\n",((struct mystruct *)mptr)->name);
	printf("%s\n",mptr->name);
//	printf("%s",((struct mystruct *)mptr)->p->name);
//	printf("%s",mptr->((struct mystruct *)p)->name);
	perror("Error printed by perror");
}


/*
int ern;
//int errno;
FILE *fp;
printf("%d\n",errno);
fp=fopen("abc.doc","r");
if(fp==NULL)
{
ern=errno;
printf("%d\n",ern);
fprintf(stderr,"value of errno is %d\n",errno);
perror("Error printed by perror");
}
return 0;
*/
