#include <unistd.h>
#include<stdio.h>
int main()
{
   FILE *fp=NULL;
   int dlen=0;
   char data[100]={0};
   int length=0;
   fp = fopen("test.txt", "w");
   if (NULL != fp)
   {
printf("++\n");    
  scanf("%s",data);
      fwrite(data,strlen(data), 1, fp);
      fclose(fp);
      fp=NULL;
      if(0 == access("test.txt",F_OK))
      {
         if((fp=fopen("test.txt","r"))==NULL)
         {
            perror("Error");
            return 1;
         }
         fseek(fp,0,SEEK_END);
         length=ftell(fp);
         printf("length=%d\n",length);
         fseek(fp,0,SEEK_SET);
         dlen=fread(data,1,length,fp);
         printf("%s\n",data);
         printf("dlen=%d\n",dlen);
      }
   }
   else
   {
      perror("Error");
   }
   if(fp != NULL)
   {
      fclose(fp);
      fp=NULL;
   }

}
