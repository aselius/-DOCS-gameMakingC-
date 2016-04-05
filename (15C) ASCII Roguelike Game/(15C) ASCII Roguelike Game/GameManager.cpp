#include "GameManager.h"
#include <conio.h>



GameManager::GameManager(string levelFileName)
{

	_player.init(1, 30, 10, 2, 0);

	_level.load(levelFileName, _player);
	system("PAUSE");
}

void GameManager::playGame() {
	bool isDone = false;

	while (isDone != true) {
		_level.print();
		playerMove();
		_level.updateEnemies(_player);
	}
}

void GameManager::playerMove() {
	char input;
	printf("Enter a move command (w/s/a/d) :");
	input = _getch();

	_level.movePlayer(input, _player);

}