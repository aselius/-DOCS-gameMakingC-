#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <string>

using namespace std;

class Level
{
public:
	Level();

	void load(string fileName, Player &player);
	void print();

	void movePlayer(char input, Player &player);
	void updateEnemies(Player &player);

	//getters and setters
	char getTile(int x, int y);
	void setTile(int x, int y, char tile);

private:
	void processPlayerMove(Player &player, int targetX, int targetY);
	void battleMonster(Player &player, int targetX, int targetY);
	void processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY);

private:
	vector <string> _levelData;
	vector <Enemy> _enemies;
};

