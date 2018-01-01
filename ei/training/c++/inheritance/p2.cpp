#include<iostream>
using namespace std;
class base
{
   protected:
      int x;
   public:
      base()
      {
         x=1;
         cout << "Base constructor called\n";
      }

      void inc()
      {
         x++;
      }

      void show()
      {
         cout << "Base Show() X:"<< x<< endl;
      }
};

class der : public base
{
   protected:
      int y;
   public:
      der() : base()
      {
         y=10;
         cout << "derived constructor called\n";
      }
      
      void dec()
      {
         x--;
         y--;
      }

      void show()
      {
         cout << "Derived Show() X:" <<x<< "  Y:" << y <<endl;
      }
};

int main()
{
   base b;
   der d;
   b.show();
   d.show();

   cout << "After increment \n";
   b.inc();
   d.inc();
   b.show();
   d.show();
   cout << "After decrement \n";
   d.dec();
   b.show();
   d.show();
}


