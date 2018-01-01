#include <iostream>
using namespace std;

class sample
{
   private:
      int data;
   public:
/*      void setdata(int d)
      {
      data= d;
      };
*/
      int show()
      {
//         cout << "Op:"<<s1.show << endl;
         return data;
      };
};

int main()
{
sample s1(1);
int d;
//s1.setdata(10);
d= s1.show();
cout << "Op:"<<d << endl;
}
