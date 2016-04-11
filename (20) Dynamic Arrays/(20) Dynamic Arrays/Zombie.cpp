#include "Zombie.h"
#include <iostream>

using namespace std;

Zombie::Zombie()
{
	_items = new int[100];
}


Zombie::~Zombie()
{
	cout << "Destructor called\n";
	delete[] _items;
}
