#include<iostream>
using namespace std;

class Box
{
   public:
      int hight;
      friend void print_hw(Box a);
   private:
      int width;
};

void print_hw(Box a)
{
   a.width=20;
   cout << "Hight:"<<a.hight<<"  Width:"<<a.width<<endl;
}

int main()
{
   Box b1;
   b1.hight=10;
   //b1.width=20;
   cout << "Hight:"<<b1.hight<<endl;
   print_hw(b1);
   return 0;

}
