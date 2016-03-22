#include <iostream>

using namespace std;

// These are function prototypes! or forward declarations!
void someFunction();
void foobarFunction(int a, int b);
void foobarFunctionCopy(int &a, int &b);

int main() {

	//a static varialble is a variable that when called/defined multiple times remains static, so that the re-calls don't influence them.
	someFunction();
	someFunction();
	someFunction();
	someFunction();
	// this would output 6,7,8,9.

	//Passing by reference!
	//	we have variables a, and b. When we use them for the function foobarFunction, a and b inside the function should be 0 and 5, but...
	int a = 5;
	int b = 10;

	cout << "When you pass a new instance..." << endl;

	foobarFunction(a, b);

	cout << "value a is " << a << endl;
	cout << "value b is " << b << endl;
	//	This  gives us 5 and 10. This happens because we passed in a new instance of the variable. We need to pass variables by reference.
	//	To do this, replace the variable input in the function with a &variable.

	cout << "When you pass by reference..." << endl;

	foobarFunctionCopy(a, b);

	cout << "value a is " << a << endl;
	cout << "value b is " << b << endl;
	//	Now we can see that a and b are outputting 0 and 5!

	system("PAUSE");
	return 0;
}

void someFunction() {
	static int i = 5;
	i += 1;
	cout << i << endl;
}

void foobarFunction(int a, int b) {
	while (a > 0 && b > 0) {
		a = a - 1;
		b = b - 1;
		// this should give us 0, 5.
	}
}

void foobarFunctionCopy(int &a, int &b) {
	while (a > 0 && b > 0) {
		a = a - 1;
		b = b - 1;
		// this should give us 0, 5.
	}
}