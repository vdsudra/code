/*   Increment */

#include<iostream>
using namespace std;

class  incr
{
   private:
      int data;
   public:
      incr()
      {
         data=0;
         cout << "constructor called \n";
      }

      void show()
      {
         cout << data <<endl;
      }

      void operator ++ ()
      {
         data++;
      }
};

int main()
{
   incr i1,i2;
   i1++;
   i1++;
   i2++;
   i1.show();
   i2.show();
}


