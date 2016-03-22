#include <iostream>
#include <string>

//If you include your own file, use quotation not <>
#include "Monster.h"

using namespace std;

int main() {

	// this is the first constructor
	Monster monster1("George");
	Monster monster2("Fred");
	// this is the second constructor!
	Monster monsters[10];

	monster1.printName();
	monster2.printName();

	monsters[0].printName();

	system("PAUSE");
	return 0;
}