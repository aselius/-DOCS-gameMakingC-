#include <iostream>
#include <string>

using namespace std;
//SIMPLE ARRAY OPERATIONS.

int basicArray() {

	//Arrays!
	//If we have 100 items or such.. instead of making 100 variables, you can make an array!

	//You call an array by using type name[];
	//You can initialize by setting it  = {value, value ...}
	string shopItemNames[4] = {"Crowbar", "Helmet", "Boots", "Belt"};

	cout << "*** Welcome to the item shop ***\n";
	
	for (int i = 0; i < 4; i++) {

		cout << shopItemNames[i] << endl;

	}

	cout << "**********************\n\n";
	cout << "What would you lime to buy?\n";

	//An array can only have a "constant size"
	//for example, if you have an 
		// int numberOfItems = 5
		// string shopItemNames[numberOfItems]
	//This causes an error. The fix is to use a const int type.

	const int numberOfItems = 5;
	//If you want to change this, you can use a vector.
	string shopItemNames2[numberOfItems];

	system("PAUSE");
	return 0;
}

//ADVANCED ARRAY OPERATIONS.

const int numberOfItems = 6;
const string shopItemNames[numberOfItems] = { "Crowbar", "Helmet", "Boots", "Belt" ,"Socks", "Axe" };

// Arrays when passed in are alwasy passed in by reference! So you don't need the & operator.
// When you do want to keep them constant, use const to disable that specific function from changing the array.
void printInventory(const int playerInventory[numberOfItems]);
void printShop();
bool buyItems(int playerInventory[numberOfItems]);

int main() {
	//tells you when the game is over
	bool isDone = false;

	//initialize inventory array
	int playerInventory[numberOfItems] = { 0, 0, 0, 0, 1, 0 };


	cout << "*** Welcome to the item shop ***\n";

	while (isDone == false) {

		printShop();

		printInventory(playerInventory);

		isDone = buyItems(playerInventory);

		cout << "\n\n\n";
	}

	system("PAUSE");
	return 0;
}

void printInventory(const int playerInventory[numberOfItems]) {
	cout << "Your inventory is: \n";
	for (int i = 0; i < numberOfItems; i++) {
		if (playerInventory[i] > 0) {
			cout << playerInventory[i] << "x " << shopItemNames[i] << endl;
		}
	}
}

void printShop() {
	
	cout << "**********************\n";

	for (int i = 0; i < numberOfItems; i++) {

		cout << i + 1 << ". " << shopItemNames[i] << endl;

	}

	cout << "**********************\n\n";
	cout << "What would you like to buy?\n\n";
}

bool buyItems(int playerInventory[numberOfItems]) {

	int input;
	cout << "What would you like to buy? Enter -1 to quit. Enter (" << 1 << "-" << 6 << "): ";
	cin >> input;
	
	if (input == -1) {
		return true; // program is over.
	}
	if (input > numberOfItems) {
		cout << "That was a bad input!\n";
		return false; //keep going.
	}

	playerInventory[input - 1]++;

	return false;
}