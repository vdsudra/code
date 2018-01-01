#include<iostream>
using namespace std;
class Box
{
   public:
      int height;
      int width;
      Box(int l,int w)
      {
         cout<<"Constructor called"<<endl;
         height=l;
         width=w;
         //cout << "Height: " << Box.height <<"Width: " << Box.width << endl;
      }
      int volume(void)
      {
         return height*width;
      }
};

int main()
{
   Box b1(10,20);
   Box b2(100,200);
   cout << "Height: " << b1.height << "  Width: " << b1.width << endl;
   cout << "Volume:" << b1.volume() <<endl;
}
