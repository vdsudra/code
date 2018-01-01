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
         data =100;
      };
      sample(int d)
      {
         cout << "i m constructor with argument\n";
         data =d;
      };

      void showdata();
      void add(sample ob1, sample ob2);
};

void sample :: showdata()
      {
         cout << data <<endl;
      }

void sample :: add(sample ob1, sample ob2)
      {
      data=ob1.data + ob2.data;
      }

int main()
{
sample s1(10), s2, s3;
s3.add(s1,s2);
s3.showdata();
}
