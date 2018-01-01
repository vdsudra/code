#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void myfun(char data)
{


printf("%s\n",data[2]);
}


int main()
{
        int len,j;
        FILE *fp=NULL;
        char  ip[10];
        unsigned int f_ip;
        int i=0;
        char data[4][10][10]={{"zero" ,"one" ,"two","three" ,"four" ,"five" ,"six" ,"seven" ,"eight" , "nine"},
                {"ten","eleven" ,"twelve" ,"thirteen" ,"fourteen" ,"fifteen" ,"sixteen" , "seventeen", "eighteen", "nineteen"},
                {"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy","eighty", "ninety" },
                {"hundred","thousand"}};

printf("%s\n",data[2][10]);

myfun(&data);
}
