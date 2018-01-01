#include<stdio.h>

char *strcp(char *s1, char *s2){
printf("1:Add  s1:%p  s2:%p\n",s1,s2);
while(*s2++ = *s1++);

printf("2:Add  s1:%p  s2:%p\n",s1,s2);
return s2;
}
int main(){
char s1[100]="Ahmedabad";
char s2[100]="Bangalore";
char *s;
s = strcp(s1,s2);
printf("S2: %s\n",s2);
printf("S: %s  :p:%p\n",s,s);
return 0;

}

