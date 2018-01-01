#include<iostream>
using namespace std;
class Adder
{
   public:
      Adder()
      {
         cout << "Constructor called" << endl;
         total=0;
      }
      void addnum(int num)
      {
         cout << "Add num called" <<endl;
         total+=num;
      }
      int gettotal()
      {
         return total;
      }
      ~Adder()
      {
         cout << "Destuctor is called" << endl;
      }
   private:
      int total;
};

int main()
{
   cout << "main()" <<endl;
   Adder a;
   cout << "Adding Start"<<endl;
   a.addnum(1);
   a.addnum(10);
   a.addnum(100);
   cout << "Total:" <<a.gettotal() << endl;
}
