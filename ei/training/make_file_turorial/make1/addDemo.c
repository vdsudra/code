#include "myMath.h"
#include <stdio.h>
 
int main()
{
  int x= 10, y = 20;
  printf("%d + %d = %d", x, y, add(x, y));
  printf("%d - %d = %d", x, y, sub(x, y));
  return 0;
}
