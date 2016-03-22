#include <iostream>
#include "Board.h"

Board::Board()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_boardStatus[i][j] = ' ';
		}
	}
}

void Board::addMarker(int r, int c, char symbol) {
	if (_boardStatus[r][c] == ' ') {
		_boardStatus[r][c] = symbol;
	}
	else {
		cout << "Invalid coordinate! Re-enter coordinates\n\n";
		cout << "Enter your y coordinates: ";
		cin >> r;
		cout << endl;
		cout << "Enter your x coordinates: ";
		cin >> c;
		cout << endl;
		addMarker(r-1, c-1, symbol);
	}

}

void Board::printBoard() {
	cout << "***************\n";
	cout << "|| " << _boardStatus[0][0] << " | " << _boardStatus[0][1] << " | " << _boardStatus[0][2] << " ||\n";
	cout << "---------------\n";
	cout << "|| " << _boardStatus[1][0] << " | " << _boardStatus[1][1] << " | " << _boardStatus[1][2] << " ||\n";
	cout << "---------------\n";
	cout << "|| " << _boardStatus[2][0] << " | " << _boardStatus[2][1] << " | " << _boardStatus[2][2] << " ||\n";
	cout << "---------------\n";
}

bool Board::checkGameOver(char symbol) {
	//check the rows
	for (int i = 0; i < 3; i++) {
		if (_boardStatus[0][i] == symbol && _boardStatus[1][i] == symbol && _boardStatus[2][i] == symbol) {
			return true;
		}
	}
	//check the columns
	for (int i = 0; i < 3; i++) {
		if (_boardStatus[i][0] == symbol && _boardStatus[i][1] == symbol && _boardStatus[i][2] == symbol) {
			return true;
		}
	}
	//check right diagonal '\'
	if (_boardStatus[0][0] == symbol && _boardStatus[1][1] == symbol && _boardStatus[2][2] == symbol) {
		return true;
	}
	//check left diagonal '/'
	if (_boardStatus[0][2] == symbol && _boardStatus[1][1] == symbol && _boardStatus[2][0] == symbol) {
		return true;
	}
	return false;
}