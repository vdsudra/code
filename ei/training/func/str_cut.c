#include<stdio.h>
#include<string.h>
void remove_ch(char *str, char*tmp,int index);
int main()
{
   char str[100]="Thisisexample";
   char tmp[100];
   int index=5;
   remove_ch(str,tmp,index);
   printf("%s\n",tmp);
}


void remove_ch(char *str, char*tmp,int index)
{
   int len =strlen(str);
   int i,j,k;
   for(i=0,j=0;i<len;i++)
   {
      if(index==i)
	 continue;
      tmp[j]=str[i];
      j++;
   }
   tmp[j]=0;
}

