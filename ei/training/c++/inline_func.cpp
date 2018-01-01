#include<iostream>
using namespace std;
inline int max(int x,int y)
{
   return ((x>y)? x:y);
}

int main()
{
   cout << "(10:20) :"<< max(10,20) << endl;
   cout << "(50:30) :"<< max(50,30) << endl;
   cout << "(99:99) :"<< max(99,99) << endl;
}

