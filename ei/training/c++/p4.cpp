#include <iostream>
using namespace std;

class sample
{
   private:
      int data;
   public:
      sample(int d=100)
      {
      cout << "I m constructor\n";
      data =d;
      cout << d << endl;
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
d= s1.show();
cout << "Op S1:"<<d << endl;

sample s2(11);
d= s2.show();
cout << "Op S2:"<<d << endl;
}
