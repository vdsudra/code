#include<iostream>
using namespace std;

class box
{
   public:
      int heigth;
      int length;
      int set_heigth(int);
      int get_width(void);
   private:
      int width;
};

int box::set_heigth(int hg)
{
   heigth = hg;
}
int box::get_width(void)
{
   return width;
}
int main()
{
   int h,w;
   box box1;
   box1.set_heigth(10);
   cout << "Hight :" << box1.heigth << endl;
   box1.length=20;
   box1.width=100;
   cout <<"Length :" << box1.length <<endl;
   w=box1.get_width();
   cout << "Width :" << w <<endl;
   return 0;

}
