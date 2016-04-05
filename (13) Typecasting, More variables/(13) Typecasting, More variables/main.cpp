#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {

	//Floating Point
	float f;
		//4 bytes (IEEE floating point rep)
	double d;
		//8 bytes
	
	//Integers
	int i;
		//unsigned cant hold negative numbers.
	unsigned int ui;
		//char is also considered an integer! (can also be unsinged) and is a byte.
		//ASCII charts!
		//char c = 90 will show "Z"
	char c;

	//Typecasting is switching the type of a variable.
	char foo = 'A';
		//if we want the integer value of A,
	cout << (int)foo << endl;

	//Integer division.
		//when you divide two integers, you will not get a float answer!
	int a = 5;
	int b = 6;
		//this will output 0
	cout << a / b << endl;
		//even if we typecast the result, this will also output 0 
		//this is because the result itself is output as an integer 0, and when you convert that to a float, it remains unchanged.
	cout << float(a / b) << endl;
		//if you change one integer to a float, you will get the right result!
	cout << float(a) / b << endl;

	system("PAUSE");
	return 0;
}