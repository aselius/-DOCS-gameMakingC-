#pragma once
// you want to keep your headerfile as small as possible.
// you could have included your #include <iostream> here but instead put it in .cpp
// this is for slight performance improvement.

#include <string>
using namespace std;

class Monster
{
public:
	//This is the constructor
	//Something that gets called everytime you create the object.
		//this is the syntax of the constructor. you dont need void.
		//you can have a multiple constructors by the way!
	Monster(string name);
	Monster();
	//This is the destructor
	//~Monster();

	void printName();

private:
	//we have a private variable name, so main.cpp can't access this.
	//what makes sense is the assign a name when you construct a monster.
	//this is a good practice because the variable is immutable.
	string _name;
};

