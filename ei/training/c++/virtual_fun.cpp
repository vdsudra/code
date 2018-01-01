#include<iostream>
using namespace std;
class shape
{
   public :
      int height;
      int width;
      virtual int get_area() = 0;
      void set_hw(int ,int);
      ~shape()
      {
         cout << "shape Distructor is called" << endl;
      }
};

void shape::set_hw(int h ,int w)
{
   height = h;
   width = w;
}

class rectangle : public shape
{
   public :
      rectangle(int h = 0 ,int w = 0)
      {
         cout<<"React Constructor called"<<endl;
         height=h;
         width=w;
      }
      int get_area()
      {
         return height*width;
      }

      ~rectangle()
      {
         cout << "rectangle Distructor is called" << endl;
      }
};

class triangle : public shape
{

   public :
      triangle(int h = 0 ,int w = 0)
      {
         height=h;
         width=w;
      }

      int get_area()
      {
         return ( height * width ) / 2;
      }
      ~triangle()      
      {
         cout << "triangle Distructor is called" << endl;
      }
};

int main()
{
   rectangle rect;
   triangle tri;
   rect.set_hw(10 ,20);
   tri.set_hw(20 ,30);
   cout << "Area Of rectangle: " << rect.get_area() << endl;
   cout << "Area Of triangle: " << tri.get_area() << endl;
   rectangle rect1(30,30); //constructor
   cout << "Area Of rectangle: " << rect1.get_area() << endl;
   cout << "******"<<endl;
}
