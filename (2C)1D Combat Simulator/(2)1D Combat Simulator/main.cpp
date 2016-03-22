#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

/*
Create a 1d Combat Simulator

- 2 sides in battle!
eg. skeletons vs. humans, plants vs. zombies, and so forth
- each faction will have a user set number of units. (ask user input!)
- each faction units will have a set health, attack damage and hit/miss chance.
eg. skeletons 5hp, 1attack 40%chance to hit; humans 15hp, 3attack 60% chance to hit.
- each fight will be a unit vs a unit (1-D) so when one unit gets killed, the next availabe fights the remaining opponent.
- use a seeded random number generator to perform the fight.
*/

//example code:
int main()
{
	mt19937 randomNumberGenerator(time(0));
	uniform_real_distribution<float> attackRoll(0.0f, 1.0f);

	int numberHumans, numberSkeletons;
	float attackChance;
	int turn = 0;

	int humanHitPoints = 15;
	int humanAttackDamage = 5;
	float humanAttackChance = 0.5f;
	int currentHumanHealth = humanHitPoints;

	int skeletonHitPoints = 5;
	int skeletonAttackDamage = 2;
	float skeletonAttackChance = 0.3f;
	int currentSkeletonHealth = skeletonHitPoints;

	cout << "Welcome to Humans vs. Skeletons\n";

	cout << "For the battle to commence, Enter the number of Humans: ";
	cin >> numberHumans;
	cout << "There are " << numberHumans << " Humans.\n";
	cout << "Now, Enter the number of Skeletons: ";
	cin >> numberSkeletons;
	cout << "There are " << numberSkeletons << " Skeletons.\n\n";
	cout << "Let the Battle Commence!\n\n" << "*BATTLE NOISES*\n\n";
	
	while (numberHumans >= 0 && numberSkeletons >= 0) {
		turn++;
		// check if a unit died to push the next one into the fight and decrease the amount of units available.
		if (currentHumanHealth <= 0) {
			numberHumans = numberHumans - 1;
			currentHumanHealth = humanHitPoints;
		}
		if (currentSkeletonHealth <= 0) {
			numberSkeletons = numberSkeletons - 1;
			currentSkeletonHealth = skeletonHitPoints;
		}

		//Skeletons by default attack first because they are .. well undead :p
		//Obtain an attackchance from the generator and if attack is successful, detract from current unit health.
		attackChance = attackRoll(randomNumberGenerator);

		if (attackChance > skeletonAttackChance) {
			currentHumanHealth = currentHumanHealth - skeletonAttackDamage;
			//cout << "Skeleton Attack successful! Current Human Health is " << currentHumanHealth << "\n";
		}/*
		else {
			cout << "Skeleton Attack unsuccessful! Current Human Health is " << currentHumanHealth << "\n";
		}*/

		attackChance = attackRoll(randomNumberGenerator);
		if (attackChance > humanAttackChance) {
			currentSkeletonHealth = currentSkeletonHealth - humanAttackDamage;
			//cout << "Human Attack successful! Current Skeleton Health is " << currentSkeletonHealth << "\n";
		}/*
		else {
			cout << "Human Attack unsuccessful! Current Skeleton Health is " << currentSkeletonHealth << "\n";
		}*/
	}
	
	cout << "Battle is over!\n";

	if (numberHumans > numberSkeletons) {
		cout << "Humans Win!\n" << "There are " << numberHumans << " Humans Left!\n";
		cout << "The battle lasted " << turn << " turns!\n";
	}
	else {
		cout << "Skeletons Win!\n" << "There are " << numberSkeletons << " Skeletons Left!\n";
		cout << "The battle lasted " << turn << " turns!\n";
	}

	system("PAUSE");
	return 0;

}