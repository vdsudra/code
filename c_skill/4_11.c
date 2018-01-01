#include<stdio.h>
int main()
{
   struct str
   {
      char name[10];
      float f;
   };

   struct str s;
   scanf("%s%f", s.name,&s.f);
   printf("Name:%s f:%f", s.name,s.f);
   return 0;
}
