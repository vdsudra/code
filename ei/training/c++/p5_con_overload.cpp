#include <iostream>
using namespace std;
class sample
{
   private:
      int data;
   public:
      sample()
      {
         cout << "i m constructor without argument\n";
         data =101;
      };
      sample(int d)
      {
         cout << "i m constructor with argument\n";
         data =d;
      };

      void showdata()
      {
      cout << data <<endl;
      };
};

int main()
{
sample s1(10), s2;
cout <<"s1:";
s1.showdata();

cout <<"s2:";
s2.showdata();
}
