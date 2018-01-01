#include<stdio.h>
int main()
{
   char s[]="vinaysudra";
   char t[20];
   char *sp, *tp;
   sp=s;
   tp=t;
   printf("%s\n",sp);
  // while(*sp)
    while(*tp++ = *sp++);
   //*tp='\0';
   printf("%s\n",t);
   return 0;
}

