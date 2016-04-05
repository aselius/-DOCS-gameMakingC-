#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int main() {

	// if else statements when too many cases, can be slow, and when we are comparing
	// to constants, we can use the switch statement instead!

	char moveSpot = 'A';

	if (moveSpot == '.') {
		printf("You can move!\n");
	}
	else if (moveSpot == '#') {
		printf("You can't move there!\n");
	}
	else if (moveSpot == 'S') {
		printf("Battle Time!\n");
	}

	// with the same logic, we can create a switch statement.
	// we need a break statement every case since if you don't have it it will process the rest of the cases.
	// cases need to contain constants. no ints etc. we could technically have a const int.
	switch (moveSpot) 
	{
	case '.':
		printf("You can move!\n");
		break;
	case '#':
		printf("You can't move there!\n");
		break;
	case 'S':
		printf("Battle Time!\n");
		break;
	}

	system("PAUSE");
	return 0;
}