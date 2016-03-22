#include <iostream>
#include <string>

using namespace std;

//Class encapsulates various functions and variables together that serves one purpose
	//eg. a monster class that attacks a player etc.

//Class vs object
//Class is a description of an object.
	//eg. class writes down properties and functionalities of a monster
	//eg. object is a monster

//Use a capital for the class (good practice)
class Monster {
public:
	void growl() {
		cout << "Growl!!!\n";
	}

	//this is a setter function. A getter function gets the name.
	void setName(string name) {
		_name = name;
	}
	string getName() {
		return _name;
	}

//good practice is for private variables/functions put a underscore
private:
	string _name;
};

int main()
{
	//create a new monster object! by using the type the class.
	Monster monster1;
	//You can only access the methods and functions inside the class if they are PUBLIC. By default they are private.
	monster1.growl();
	monster1.setName("George");

	cout << monster1.getName() << endl;

	system("PAUSE");
	return 0;
}