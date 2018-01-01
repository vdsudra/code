#include<stdio.h>
int main()
{
   struct str
   {
    double d; 
    char i;
    int k;
    int m;
    char t;
    int a;
    char b;
   };

   struct  __attribute__ ((__packed__)) strq
   {
    double d; 
    char i;
    int k;
    int m;
    char t;
   };

   printf("Size of Double : %d Bytes\n",(int)sizeof(double));
   printf("Size of Char : %d Bytes\n",(int)sizeof(char));
   printf("Size : %d Bytes\n",(int)sizeof(struct str));
   printf("Sizeq: %d Bytes\n",(int)sizeof(struct strq));
   return 0;
}


