#include<iostream>
using namespace std;

class op
{
   private :
      int a;
   public:
      op (int d=0)
      {
         a=d;
      }
      void show()
      {
         cout << a << endl;
      }

      op operator + (op o1)
      {
         op tmp;
         tmp.a=a+o1.a;
         return tmp;
      }
      
      op operator - (op o1)
      {
         op tmp;
         tmp.a=a-o1.a;
         return tmp;
      }

      op operator * (op o1)
      {
         op tmp;
         tmp.a=a*o1.a;
         return tmp;
      }
      op operator / (op o1)
      {
         op tmp;
         tmp.a=a/o1.a;
         return tmp;
      }
};
int main()
{
   op x(10),y(2),z;
   z=x+y;
   z.show();

   z=x-y;
   z.show();

   z=x*y;
   z.show();

   z=x/y;
   z.show();
}

