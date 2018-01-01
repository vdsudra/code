#include<stdio.h>
int main(int argc ,char *argv[])
{
int i=0;
/*for(i=0;i<argc;i++)
{
printf("%d   %lu  %s\n",i,argv,*argv);
argv++;
}*/
for(i=0;i<argc;i++)
{
printf("%s%s",*++argv,(argc > 1) ? " " : "");

}
printf("\n");
printf("Size:%d\n",fsize("cmd_arg.c"));
return 0;


}
