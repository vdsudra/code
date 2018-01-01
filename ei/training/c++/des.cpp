#include<iostream>
using namespace std;

class xyz
{
   private:
      int x,y;
   public:
      xyz()
      {
         x=10;
         y=20;
      }

      void show()
      {
         cout<<"X:"<<x<<"Y:"<<y<<endl;
      }

      ~xyz()
      {
         cout<<"Exit\n";
      }
};

void fun()
{
   xyz a;
   a.show();
}

int main()
{
   cout<<"Before\n";
   fun();
   cout<<"After\n";
}


