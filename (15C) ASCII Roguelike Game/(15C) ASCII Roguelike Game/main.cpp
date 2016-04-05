#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
//ASCII ROGUELIKE GAME!!
// 1. Load the ASCII levels from txt
// 2. Allow player movement with w s a d. 
	//getch() or _getch(); comes with conio.h and
	//monitors the keys pressed.
// 3. Have enemies that randomly move around. Allow players to attack them.
// 4. Make sure player can't walk through walls.
// Optional
// 5. Savable game.
// 6. Add items and money to the game and an item shop.
// 7. Allow the player to level up when he gets experience.
// 8. Have multiple levels.

// Can use # for walls . for air @ for player and letters for monsters.
// Store your game level in a vector of string, each string is a row in the level.
	//treat this vector of strings as a 2D array
// When player or monster wants to move in a direction, first check what char is on the board in that direction.
	//Use a switch statement to evaluate what should happen.
// Use an ifstream and getline function to load your level from a .txt file. Load one row at a time and put them in a string
	//then push back each string to your vector.
// Surround level with walls
// Creat a Monster class and store the monsters in a vector <Monster> monsters.
	//every time you loop through the main game loop, you can loop through this monsters array and randomly move each one.

//Example Code

#include "GameManager.h"

using namespace std;

int main() {

	GameManager gameManager("level1.txt");
	
	gameManager.playGame();

	return 0;
}


//Player Class, Monster Class, Map Class, GameManager Class