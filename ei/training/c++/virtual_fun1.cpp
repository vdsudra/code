#include <iostream>
using namespace std;

class Weapon
{
	public:
		void loadFeatures()
		{ cout << "Loading weapon features.\n"; }
};

class Bomb : public Weapon
{
	public:
		void loadFeatures()
		{ cout << "Loading bomb features.\n"; }
};

class Gun : public Weapon
{
	public:
		void loadFeatures()
		{ cout << "Loading gun features.\n"; }
};

int main()
{
	Weapon w ;
	Bomb b ;
	Gun g ;
	Weapon *w1 = &g;

	w.loadFeatures();
	b.loadFeatures();
	g.loadFeatures();
	w1->loadFeatures();

	return 0;
}																					
