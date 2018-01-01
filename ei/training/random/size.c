#include <stdio.h>
int main()
{
struct __attribute__ ((__packed__)) data_size
{
int i;
char ch;
char buffer[1024];
}data;

printf("Strlen befor:%d",sizeof(data));

}
