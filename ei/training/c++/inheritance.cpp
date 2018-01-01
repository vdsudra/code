#include<iostream>
using namespace std;
class box
{
   public:
      int h;
      int w;
      void set_hw(int hi,int wi)
      {
         h=hi;
         w=wi;
      }
};

class rectangle: public box
{
   public:
      int get_area()
      {
         return h*w;
      }
};

int main()
{
   rectangle r;
   r.set_hw(10,20);
   cout<<"Area: " << r.get_area() << endl;

}
