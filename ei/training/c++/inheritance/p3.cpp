#include<iostream>
#include<string.h>
using namespace std;

class data
{
   private:
      char name[20];
      int age;
   public:
      data(char n[20], int a)
      {
         strcpy(name, n);
         age = a;
      }
      void show()
      {
         cout << "Name: " << name  << "Age: " << age<<endl;
      }
};

class student : public data
{
   protected:
      int per;
   public:
      student(char n[20], int a,int p) : data(n,a)
   {
      per=p;
   }
      
      void show()
      {
         data :: show();
         cout << "Percentage: " << per << endl;
      }
};


class teacher : public data
{
   protected:
      int sal;
   public:
      teacher(char n[20], int a,int s) : data(n,a)
   {
      sal =s;
   }
      void show()
      {
         data :: show();
         cout << "Salary: " << sal << endl;
      }
};

int main()
{
   student s1("Vinay", 25, 99), s2("sudra", 26 ,98);
   teacher t1("Vinay", 25, 25000), t2("sudra", 26 ,30000);
   s1.show();
   s2.show();
   t1.show();
   t2.show();
}
