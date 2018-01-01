#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
   struct str
   {
      char *n;
      int age;
   };

   struct strr
   {
      char n[20];
      int age;
   };

   struct strr s1={"Vinay",26};
   struct strr s3={"Vinay",26};
struct str *ptr;
ptr = (struct str *)alloca(sizeof(struct str));
if(ptr == NULL)
{

   printf("Erro\n");
   return ;
}


getchar();
   printf("Arg[0]:%s\n",argv[0]);
   //struct str s2=s1;
   if(s1.n == s3.n)
   {
   printf("S1 and S3 are same\n");
   return 0;
   }
   else
   return 0;
   /*
   printf("S1:%s\n",s1.n);
   printf("S2:%s\n",s2.n);
   
   struct strr s11={"Vinay",26};
   struct strr s22=s11;
   printf("S11:%s\n",s11.n);
   printf("S22:%s\n",s22.n);
   printf("S22:%d\n",s22.age);
*/
while(1);
}


