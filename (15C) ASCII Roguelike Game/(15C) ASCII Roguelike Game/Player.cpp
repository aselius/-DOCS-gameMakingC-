#include "Player.h"
#include <random>
#include <ctime>

using namespace std;

Player::Player()
{
	_x = 0;
	_y = 0;
}

void Player::init(int level, int health, int attack, int defense, int experience) {
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience;
}

void Player::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

void Player::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}

int Player::attack() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

void Player::addExperience(int experience) {
	_experience += experience;
	
	//level up.
	while (_experience > 50) {
		printf("%i Experience\n", _experience);
		printf("Leveled Up!\n");
		_experience -= 50;
		_attack += 10;
		_defense += 5;
		_health += 25;
		_level++;
	}
}

int Player::takeDamage(int attack) {
	attack -= _defense;
	//check if attk does dmg
	if (attack > 0) {
		_health -= attack;
		//check if died
		if (_health <= 0) {
			return 1;
		}

	}
	return 0;
}