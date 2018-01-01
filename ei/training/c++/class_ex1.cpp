#include<iostream>
using namespace std;
class Box
{
   public:
      int hight;
      int length;
      int width;
      int GetVol(void)
      {
         return hight * length *width;
      };

};
/*int Box::GetVol(void)
{
return hight * length *width;
}*/

int main()
{
   int vol;
   Box box1;
   box1.hight=10;
   box1.length=10;
   box1.width=10;
   vol=box1.GetVol();
   cout << "volume:" <<  vol << endl;

}
