#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	mt19937 randomGenerator(time(0));
	// This is a random number generator with a seed. 
	// The same random number is generated when you use the same seed.
	uniform_real_distribution<float> attackRoll(0.0f, 1.0f);

	float attack = attackRoll(randomGenerator);

	cout << "I am attacking! " << attack << endl;

	if (attack >= 0.3f) {
		cout << "I hit the snake!\n";
	}
	else {
		cout << "I missed the snake!\n";
	}

	system("PAUSE");
	return 0;
}