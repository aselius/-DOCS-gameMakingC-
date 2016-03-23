#include <iostream>
#include <string>
#include <cstdlib>
//fstream is reading and writing out to a file, not the command line!
//we need to create an instance, however, unlike iostream.
#include <fstream>

using namespace std;

int main() {
	// We should make use of a saved file when making a game. A file output / input needs to be utilized instead of starting with a clean slate everytime.

	//We create an instance to the fstream here.
	ofstream outputFile;
	ifstream inputFile;

	//the default is to write to the file.
	//if the file does not exist, will create the file.
	outputFile.open("myFile.txt");
	//should check if it opened correctly.
	if (outputFile.fail()) {
		perror("myFile.txt");
		return 1;
	}

	// just as iostream, cout
	outputFile << "Hello World!\n";
	// need to close file worked on.
	outputFile.close();

	//for opening files,

	//same as before, we open file, and put a condition for error.
	inputFile.open("myFile.txt");
	if (inputFile.fail()) {
		//this perror would output an error message.
		perror("myFile.txt");
		return 1;
	}
	//if we take in the input as such, with a cin >> like structure,
	string input;
	inputFile >> input;
	//you would get "Hello"
	cout << input;
	//this is because cins, and fins only take the first word, and since there is a blank space between Hello and World, only Hello.
	//we can use the getline instead.
	//getline(file, var);
	getline(inputFile, input);

	//if you want all of the file,
	//we can use getline or an extraction in a while loop.
	
	//extraction method.
		//inputFile >> input is a boolean statement. True if you got something in the variable! False if not.
	while (inputFile >> input) {
		cout << input;
	}
	//getline method.
		//same boolean here.
		//getline will get the whitespace, but not the end lines. so add endl after cout << input
	while (getline(inputFile, input)) {
		cout << input << endl;
	}

	//when we input something that is not in accordance with the variable type, cin will come across an error.
		//we can set up an error message as such, but this wont solve the problem as the value we put into a,
		//will still be there and the boolean will always be false. So we need to clear what is in cin >> a.
	while (true) {
		int a;
		if (!(cin >> a)) {
			cout << "That is not a valid argument.\n";
			system("PAUSE");
			//we do this by clearing the input stream
			cin.clear();
			cin.ignore(9999, '\n');
			//this (clean first and then ignore) ignores 9999 characters before '\n'
		}
		cout << a;
	}

	system("PAUSE");
	return 0;
}