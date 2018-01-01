#include <stdio.h>
int main()
{
	char *s ="NULL\0";
	const int i=9;

	printf("%d\n", i);

	int *p = &i;
	(*p)++;
	printf("%d\n", i);
}
