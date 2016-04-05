#pragma once
#include "Player.h"
#include "Level.h"
#include <string>

//None of the other systems include gameManager!
//They dont need to know about gameManager.
//We have encapsulated a bunch of functionality in the gameManager
//Keeps circularincludes from happening.
//But we dont want this to do all the work, that is why a lot of the 
//functionalities are included in levels.. etc.

using namespace std;

class GameManager
{
public:
	GameManager(string levelFileName);
	void playGame();
	void playerMove();

private:
	Player _player;
	Level _level;
	//you can pass in vectors by reference.
	//in fact you should always pass by reference if you want to change, and if you dont, make it constant.
	
};

