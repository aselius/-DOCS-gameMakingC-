#include <iostream>
//need to include vector
#include <vector>
#include <string>
#include <list>

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

	cout << "This is a list\n\n";
	list<string> itemNamesList;

	//theres push_front and pop_front in addition!
	itemNamesList.push_back("Junk");
	itemNamesList.push_front("Gloves");
	itemNamesList.push_back("Kittens");
	itemNamesList.push_back("Swords");
	itemNamesList.push_back("Arrows");

	//you can simply delete items in a list by using the remove method. This keeps the original order of items.
	itemNamesList.remove("Kittens");

	//you can't use the same for loop as the vector. need to use an iterator.
	list<string>::iterator it;
	//this now points to the beginning of the list and stops when it reaches the end.
	//on first iteration points at first, it++, then second... so on.
	for (it = itemNamesList.begin(); it != itemNamesList.end(); it++) {
		//now we get introduced to pointers!
		//this refers to what it points to.
		cout << *it << endl;
	}

	//another remove function is "erase" since we are removing all strings called Kittens by using remove.
	itemNamesList.push_back("Kittens");
	itemNamesList.push_back("Kittens");

	cout << "This has 2 kittens\n";

	for (it = itemNamesList.begin(); it != itemNamesList.end(); it++) {
		cout << *it << endl;
	}

	cout << "This has 1 kitten\n";

	for (it = itemNamesList.begin(); it != itemNamesList.end(); it++) {
		if (*it == "Kittens") {
			//this would erase one occurence of kittens!
			it = itemNamesList.erase(it);
			break;
		}
	}

	for (it = itemNamesList.begin(); it != itemNamesList.end(); it++) {
		cout << *it << endl;
	}

	system("PAUSE");
	return 0;
}