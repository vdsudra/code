#include<iostream>
using namespace std;
int main()
{
   int i=10;
   const int &ref=i++;
  

   cout<<"I: "<< i<< "ref: "<<ref<<endl;
   i+=10;
   cout<<"I: "<< i<< "ref: "<<ref<<endl;
}
