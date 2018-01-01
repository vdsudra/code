#include<stdio.h>
int main()
{
   int i;
   char j;
   float k;
   double l;
   printf("int  :%d\nchar :%d\nfloat  :%d\ndouble :%d\n", sizeof(i), sizeof(j), sizeof(k), sizeof(l));
   printf(" sizeof(10):%d  sizeof(10.0):%d   sizeof(vinay):%d\n",sizeof(10),sizeof(10.0),sizeof("vinay"));
   printf("sizeof(i=456):%d\n",sizeof(j=456));
   return 0;
}
