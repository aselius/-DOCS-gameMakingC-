#include <iostream>
//need to include vector
#include <vector>
#include <string>

using namespace std;

int main() {
	
	//arrays don't allow you to change the size of the array
	//and you need a constant int
	//vectors can be used when you need to change the size as they keep track of its own size.
	string shopItemNames[3] = { "Gloves", "Canadian Hockey Stick", "Crowbar" };

	//create a vector
	//you don't need to initialize with a {} or whatever. it is a constructor itself.
	//you can initialize the size with (5,"Missing item")
	//it is a class in itself, so you can call methods such as size.
	vector<string> itemNames(5,"MISSING ITEM");

	//you can push_back to add an item or or pop_back to remove an item
	//HOWEVER, this is last in first out, and if you wanted to get rid of elements in the middle cant pop_back.
	vector<string> itemNamesCopy;
	itemNamesCopy.push_back("Gloves");
	itemNamesCopy.push_back("Hats");
	itemNamesCopy.push_back("Axes");
	itemNamesCopy.push_back("Rocks");
	
	//if we do not care about the order of the items, you can take the last item and trade it with the specific item.
	//for example, if we wanted to get rid of Hats,
	itemNamesCopy[1] = itemNamesCopy.back();
	itemNamesCopy.pop_back();

	//if you are going to remove as such often, or you care about the order, you need to use a list.
	//arrays are faster to loop through for loop though.

	cout << "This is a vector\n\n";
	cout << itemNames.size() << endl;

	for (int i = 0; i < itemNamesCopy.size(); i++) {
		cout << itemNamesCopy[i] << endl;
	}
	cout << endl;




	system("PAUSE");
	return 0;
}