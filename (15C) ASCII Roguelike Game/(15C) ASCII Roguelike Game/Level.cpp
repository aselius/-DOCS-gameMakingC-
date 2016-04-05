#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>


Level::Level()
{
}

void Level::load(string fileName, Player &player) {

	ifstream file;

	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while (getline(file, line)) {
		_levelData.push_back(line);
	}

	file.close();

	//Process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			switch (tile) {
			case '@': //Player
				player.setPosition(j,i);
				break;
				//use default for else
			case 'S': //Snake
				_enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'g':
				_enemies.push_back(Enemy("Goblin", tile, 2, 10, 3, 15, 150));
				_enemies.back().setPosition(j, i);
				break;
			case 'o':
				_enemies.push_back(Enemy("Ogre", tile, 4, 20, 20, 200, 3000));
				_enemies.back().setPosition(j, i);
				break;
			case 'b':
				_enemies.push_back(Enemy("Bandit", tile, 3, 15, 15, 100, 1000));
				_enemies.back().setPosition(j, i);
				break;
			case 'D':
				_enemies.push_back(Enemy("Dragon", tile, 2000, 1000, 3000, 1500, 50000));
				_enemies.back().setPosition(j, i);
				break;
			}
		}
	}

}


void Level::movePlayer(char input, Player &player) {

	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	switch (input) {
	case 'w':
	case 'W':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's':
	case 'S':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a':
	case 'A':
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd':
	case 'D':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		printf("invalid input \n\n");
		system("PAUSE");
		exit(1);
	}
}

void Level::updateEnemies(Player &player) {
	char aiMove;
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;

	
	player.getPosition(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++) {
		aiMove = _enemies[i].getMove(playerX,playerY);
		_enemies[i].getPosition(enemyX, enemyY);
		switch (aiMove) {
		case 'w':
			processEnemyMove(player, i, enemyX, enemyY - 1);
			break;
		case 's':
			processEnemyMove(player, i, enemyX, enemyY + 1);
			break;
		case 'a':
			processEnemyMove(player, i, enemyX - 1, enemyY);
			break;
		case 'd':
			processEnemyMove(player, i, enemyX + 1, enemyY);
			break;
		}
	}
}

void Level::print() {

	cout << string(100, '\n');

	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}


char Level::getTile(int x, int y) {
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) {
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player &player, int targetX, int targetY) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);


	char moveTile = getTile(targetX, targetY);
	switch (moveTile) {
	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	case '#':
		break;
	default:
		battleMonster(player, targetX, targetY);
		break;
	}
}

void Level::processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY) {
	int enemyX;
	int enemyY;

	_enemies[enemyIndex].getPosition(enemyX, enemyY);

	char moveTile = getTile(targetX, targetY);
	switch (moveTile) {
	case '.':
		_enemies[enemyIndex].setPosition(targetX, targetY);
		setTile(enemyX, enemyY, '.');
		setTile(targetX, targetY, _enemies[enemyIndex].getTile());
		break;
	case '@':
		battleMonster(player, enemyX, enemyY);
		break;
	default:
		break;
	}
}

void Level::battleMonster(Player &player, int targetX, int targetY) {

	int enemyX;
	int enemyY;
	int playerX;
	int playerY;

	int attackRoll;
	int attackResult;
	string enemyName;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++) {
		_enemies[i].getPosition(enemyX, enemyY);
		

		if (targetX == enemyX && targetY == enemyY) {
			enemyName = _enemies[i].getName();

			//Battle!
			attackRoll = player.attack();
			attackResult = _enemies[i].takeDamage(attackRoll);
			int enemyHealth = _enemies[i].getHealth();
			printf("Player attacked %s with a roll of %d and the %s has %i health left.\n", enemyName.c_str(), attackRoll, enemyName.c_str(), enemyHealth);
			system("PAUSE");
			if (attackResult != 0) {
				setTile(targetX, targetY, '.');
				print();
				printf("%s Died!\n", enemyName.c_str());
				
				//remove the enemy killed
				_enemies[i] = _enemies.back();
				_enemies.pop_back();
				i--;

				system("PAUSE");
				player.addExperience(attackResult);
				return;
			}
			//Monster turn!

			print();

			attackRoll = _enemies[i].attack();
			attackResult = player.takeDamage(attackRoll);
			int playerHealth = player.getHealth();
			printf("%s attacked player with a roll of %d and the player has %i health left.\n", enemyName.c_str(), attackRoll, playerHealth);
			system("PAUSE");
			if (attackResult != 0) {
				setTile(playerX, playerY, 'x');
				print();
				printf("You Died!\n");
				system("PAUSE");
				
				exit(0);
			}
			
			return;
		}
	}
}