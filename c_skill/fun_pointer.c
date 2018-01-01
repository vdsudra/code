#include <stdio.h>
// A normal function with an int parameter
 // and void return type
 void fun(int a)
 {
     printf("Value of a is %d\n", a);
 }
      
int main()
{
   void (*fun_ptr)(int) = fun;
   (*fun_ptr)(10);
   return 0;
}
