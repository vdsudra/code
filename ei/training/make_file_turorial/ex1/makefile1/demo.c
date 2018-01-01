#include <myMath.h>
#include <stdio.h>
 
int x= 10, y = 20;
int main()
{
  printf("%d + %d = %d\n", x, y, add(x, y));
  printf("%d + %d = %d\n", x, y, sub(x, y));
  return 0;
}
