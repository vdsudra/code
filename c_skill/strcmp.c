#include<stdio.h>
#include<string.h>

int StrCmp(char *str1, char *str2)
{

   int i=0;
   while((str1[i] == str2[i]) && (str1[i] && str2[i]))
      i++;
   if(str1[i] > str2[i])
      return 1;
   else if(str1[i] < str2[i])
      return -1;
   else
      return 0;

}

int main()
{
   char s1[10]={0};
   char s2[10]={0};

   scanf("%s",s1);
   scanf("%s",s2);

   printf("%d\n",StrCmp(s1,s2));
   printf("%d\n",strcmp(s1,s2));

}

