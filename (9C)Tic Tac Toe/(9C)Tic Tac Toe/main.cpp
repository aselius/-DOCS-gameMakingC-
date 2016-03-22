#include <iostream>
#include <string>

#include "Player.h"
#include "Board.h"

using namespace std;

string getName(int index);
char getSymbol(int index, string name);
void playTurn(Player player1, Player player2, Board game, bool gameOver);

int main() {

	int numberOfPlayers;
	bool gameOver = false;

	cout << "*****Welcome to the game of Tic Tac Toe!*****\n" << "*********************************************\n\n";
	cout << "This is a game for two players.\n";
	cout << endl;
	
	string nameOne = getName(1);
	string nameTwo = getName(2);
	char symbolOne = getSymbol(1, nameOne);
	char symbolTwo = getSymbol(2, nameTwo);

	Player playerOne(nameOne, symbolOne);
	Player playerTwo(nameTwo, symbolTwo);

	cout << "Let the game begin! \n\n";
	Board game;

	playTurn(playerOne, playerTwo, game, gameOver);

	cout << "Game has ended! \n\n";	

	system("PAUSE");
	return 0;
}

string getName(int index) {
	string name;
	cout << "Player " << index << ", What is your name? ";
	cin >> name;
	cout << endl;
	return name;
}

char getSymbol(int index, string name) {
	char symbol;
	cout << name << ", What do you want your symbol to be? ";
	cin >> symbol;
	cout << endl;
	return symbol;
}

void playTurn(Player player1, Player player2, Board game, bool gameOver) {
	string nameOne = player1.getName();
	char symbolOne = player1.getSymbol();
	string nameTwo = player2.getName();
	char symbolTwo = player2.getSymbol();
	int x, y;
	while (gameOver == false) {
		cout << nameOne << ", it is your turn to play!\n\n";
		game.printBoard();
		cout << "Enter your y coordinates: ";
		cin >> y;
		cout << endl;
		cout << "Enter your x coordinates: ";
		cin >> x;
		cout << endl;
		game.addMarker(y-1, x-1, symbolOne);
		game.printBoard();
		gameOver = game.checkGameOver(symbolOne);

		cout << nameTwo << ", it is your turn to play!\n\n";
		game.printBoard();
		cout << "Enter your y coordinates: ";
		cin >> y;
		cout << endl;
		cout << "Enter your x coordinates: ";
		cin >> x;
		cout << endl;
		game.addMarker(y-1, x-1, symbolTwo);
		game.printBoard();
		gameOver = game.checkGameOver(symbolTwo);
	}
}