#include <iostream>
#include "Monster.h"
//header files are where all the prototypes go!

//Monster::Monster refers to the fact that Monster function belongs to the monster class.
Monster::Monster(string name)
{
	_name = name;
}

Monster::Monster() {
	_name = "NONAME";
}

//This print name function is Monster's function
void Monster::printName() {
	cout << "My name is " << _name << endl;
}

/*
Monster::~Monster()
{
}
*/