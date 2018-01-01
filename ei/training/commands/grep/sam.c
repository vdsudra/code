#include <stdio.h>

int main()
{
   FILE *fp;
   char str[60];

   fp = fopen("file.txt" , "r");
   if(fp == NULL) 
   {
      perror("Error opening file");
      return(-1);
   }
while(!feof(fp))
{
  if( fgets (str, 60, fp)!=NULL ) 
   {
      printf("%s",str);
   }
}
   fclose(fp);
   
   return(0);
}
