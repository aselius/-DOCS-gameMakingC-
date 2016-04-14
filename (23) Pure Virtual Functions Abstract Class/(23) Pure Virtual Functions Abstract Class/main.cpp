#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Enemy {
public:
	//this is a pure virtual function
	virtual void attack() = 0;
};

class Scorpion : public Enemy {
public:
	void attack() {
		cout << "Scorpion is attacking!";
	}
};

class Vampire : public Enemy {
public:
	void attack() {
		cout << "Vampire is attacking!";
	}
};

//So scorpion and a vampire is a type of enemy and both have an attack function

int main() {
	vector <Enemy*> enemies;
	//this is using polymorphism again but since these are a form of enemy and do not need the
	//enemy class to have an attack function that does something, we can create it to be a pure virtual function so that
	//the subclass that derive from the enemy class have to overwrite the functions provided in this "abstract class" Enemy.
	//enemies.push_back(new Enemy); will not work! since Enemy is now an abstract class! (or an interface)
	enemies.push_back(new Scorpion);
	enemies.push_back(new Vampire);

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->attack();
	}

	char tmp;
	cin >> tmp;
}