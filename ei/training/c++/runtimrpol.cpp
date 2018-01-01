#include <iostream>
using namespace std;

class Parent{
	public:
		virtual void Print(){
			cout << "Parent class print is called\n";
		}
};

class Child : public  Parent{
	public:
		void Print(){
			cout << "Child class print is called\n";
		}
};

int main(){
	Parent p, *ptr;
	Child c, *cptr;
	p.Print();
	c.Print();
	ptr=&c;
	cptr=&p;
	ptr->Print();

}
