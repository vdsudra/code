#include <stdio.h>
 
long int fact(long int z);
 
void main()
{
    int n, r, ncr;
 
    scanf("%d %d", &n, &r);
    ncr = fact(n) / (fact(r) * fact(n - r));
    printf("\n The value of ncr is: %d\n", ncr);
}
 
long int fact(long int n)
{
   if (n >= 1)
      return n*fact(n-1);
   else
      return 1;
}
