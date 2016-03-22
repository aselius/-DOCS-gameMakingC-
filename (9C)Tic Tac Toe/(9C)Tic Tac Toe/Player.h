#pragma once

#include <string>

using namespace std;

class Player
{
public:
	Player(string name, char symbol);

	string getName();
	char getSymbol();

private:
	string _name;
	char _symbol;
};

