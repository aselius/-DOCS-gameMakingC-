#pragma once

#include <string>

using namespace std;

class Board
{
public:
	Board();

	void addMarker(int r, int c, char symbol);
	void printBoard();
	bool checkGameOver(char symbol);

private:
	char _boardStatus[3][3];
};

