#include<iostream>
using namespace std;

class base
{
   protected :
      int x;
   public :
      base ()
      {
         x=100;
      }

      void plus()
      {
         x++;
      }
      void show()
      {
         cout << "from base class func " << x << endl;
      }
};

class der : public base
{
   protected:
      int y;
   public:
      der()
      {
         y=200;
      }

      void minus()
      {
         y--;
         x--;
      }
      void show()
      {
         cout << "From derived class func "<< x <<"  "<< y <<endl;
      }
};

int main()
{
   base b1;
   der d1;
   b1.show();
   d1.show();

   cout << "After ++\n";
   b1.plus();
   d1.plus();
   b1.show();
   d1.show();

   cout << "After --\n";
   //b1.minus();
   //b1.minus();
   d1.minus();
   d1.minus();
   d1.show();
}




