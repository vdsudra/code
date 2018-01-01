#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct mydata
{
   int *video;
   long int *fl;
};
struct hour
{
   int ff;
   int *video;
   long int *fl;
};
struct context
{
   int num;
   struct hour *ch;
};

int myfun(struct context *ctx  )
{
   ctx->ch=(struct hour *)calloc(1,sizeof(struct hour)*2);
   if(NULL==ctx->ch)
   {
      printf("Fail to allocate memory hour\n");
      return -1;
   }
   int i;
   for(i=0;i<2;i++)
   {
      ctx->ch[i].video=(int *)calloc(1,sizeof(int)*8);
      if(NULL==ctx->ch[i].video)
      {
         printf("Fail to allocate memory for video\n");
         return -1;
      }
   }

   for(i=0;i<2;i++)
   {
      ctx->ch[i].fl=(long int *)calloc(1,sizeof(long int)*8);
      if(NULL==ctx->ch[i].fl)
      {
         printf("Fail to allocate memory for frame loss\n");
         return -1;
      }

   }
   int j;
   for(i=0;i<2;i++)
   {
      for(j=0;j<8;j++)
      {

         ctx->ch[i].fl[j]=j*1000;
         ctx->ch[i].video[j]=j;
      }
   }
}

int myfun2(struct context *ctx)
{

   int i,j;
   printf("====================================Before=====================================\n");
   for(i=0;i<2;i++)
   {
      for(j=0;j<8;j++)
      {
         printf("  %d Video=%d  frame loss=%ld\n",i,ctx->ch[i].video[j],ctx->ch[i].fl[j]);
      }
   }
   for(i=0;i<2;i++)
   {
      for(j=0;j<8;j++)
      {
         ctx->ch[i].video[j]++;
         ctx->ch[i].fl[j]++;
      }
   }
   
   printf("====================================After=====================================\n");
   for(i=0;i<2;i++)
   {
      for(j=0;j<8;j++)
      {
         printf("  %d Video=%d  frame loss=%ld\n",i,ctx->ch[i].video[j],ctx->ch[i].fl[j]);
      }
   }
}
int main()
{
   struct context app;
   memset(&app,0x00,sizeof(struct context));
   myfun(&app);
   myfun2(&app);


   if(NULL != app.ch->fl)
      free(app.ch->fl);
   if(NULL != app.ch->video)
      free(app.ch->video);
   if(NULL != app.ch)
      free(app.ch);


}
