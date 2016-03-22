#include <iostream>
#include <string>

using namespace std;

//this is a single dimensional arry
int playerInventory[6] = { 0,0,0,0,1,0 };

//what if we want a multi dimensional array like a checkerboard (or a matrix)
//think of tic tac toe

//this creates a 2 by 6 array! row x column
int ArrayTwo[2][6] = { { 0,0,0,0,0,0 },{ 0,0,0,0,0,0 } };

int a = 5;
int b = 4;


class CheckerBoard {
public:
	void initBoard() {
		//this would initialize the checkerboard.
		//we want a 'o' as blackspace and 'x' as whitespace.
		//hardcoding with board[0][0] = 'o' and so forth will take too long...
		//we can use a modulus.
		//if we take a number with modulo to 2, we can determine odd and even.

		//we can use 2 for loops to repeat for every space in a row and a column.
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if ( (x + y) % 2 == 0) {
					board[y][x] = 'o';
				}
				else {
					board[y][x] = 'x';
				}
			}
		}
	}
	void printBoard() {
		//this prints the board on the command line.
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				cout << board[y][x];
			}
			cout << endl;
		}
	}
private:
	char board[8][8];
};

int main() {
	// this is a modulus operaton %.
	// you get the remainder after the division.
	cout << a % b << endl;

	CheckerBoard checkerBoard;
	checkerBoard.initBoard();
	checkerBoard.printBoard();

	system("PAUSE");
	return 0;
}