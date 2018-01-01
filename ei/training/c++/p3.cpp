#include <iostream>
using namespace std;

class sample
{
   private:
      int data;
   public:
      sample()
      {
      cout << "I m constructor\n";
      }
      void setdata(int d)
      {
      data= d;
      };

      int show()
      {
         return data;
      };
};

int main()
{
sample s1;
int d;
s1.setdata(10);
d= s1.show();
cout << "Op:"<<d << endl;
}
