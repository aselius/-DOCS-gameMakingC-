#include <iostream>
#include <string>

using namespace std;

//Inheritance is needed to prevent creating a GIANT class that encompasses every possible
//method and value. It makes much more sense to create a different class that inherits from
//one class.

//For example, instead of having a monster class that has a possible action for any monster
//we can create a monster class with the common elements such as name, move and attack and
//create subclasses such as spiders and goblins that will inherit the properties of the monster
//class but have properties and methods of their own.

class Monster {
public:
	//since we are creatin subclasses, we need to create a default constructor.
	Monster() {
	};

	Monster(string name) {
		_name = name;
	}

	void attack() {
		cout << _name << "is attacking!\n";
	}

	void move() {
		cout << _name << "is moving!\n";
	}

	//if you alot private variables, we cannot access it outside of the Monster class
	//even if it is inside the subclass. To solve this we can use it inside a protected qualifier.
	//It is the same as the private qualifier except you can use it in a subclass.
protected:
	string _name;

private:


};

//We make a subclass with the following syntax.
class Spider : public Monster {
public:
	Spider(string name) {
		_name = name;
	}

	void climb() {
		cout << _name << "is climbing\n";
	}

private:
};

int main() {
	Spider monster("Bob");

	monster.move();
	monster.attack();
	monster.climb();

	int a;
	cin >> a;
	return 0;
}