/*   + additon operator */

#include<iostream>
using namespace std;

class  adop
{
   private:
      int data;
   public:
      adop(int d=100)
      {
         data=d;
         cout << "constructor called \n";
      }


      void show()
      {
         cout << data <<endl;
      }

      adop operator + (adop d)
      {
         adop tmp;
         tmp.data=data+d.data;
         cout << data <<endl;
         data +=d.data;
         return tmp;
      }
};

int main()
{
   adop a1(10),a2(15),a3;
   a3=a1+a2;
   a3.show();
   a1.show();
   adop a4(11);
   a4= a4+9;
   a4.show();
}


