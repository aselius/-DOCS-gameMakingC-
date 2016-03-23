#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int pyramidSize;
void selectPyramidSize();

int main() {
	//cout prints something to the screen.
	int a = 5000;
	float c = 0.54747575757575f;
	cout << a << " " << c << endl;
	//cout cuts out a lot of the decimals. Not just because of the limitation of the floating point.

	//This is an alternative.
	printf("Hello World\n");
	//we dont use an insertion <<, rather you use an indicator, and put what that refers to.
	printf("Hello: %d %f\n", a, c);
	//what is good about printf is you can focus on formatting.
		//this refers to 10 space before d (right justify), 2 decimals (precision) for float!
	printf("Hello: %10d %.2f\n", a, c);

	//for string we use %s
	//string is a c++ class and printf is a c function.
	//so... we need to make a cstring!

	//this is a c string (well an array)
		//you don't have to specify the length of the cstring. compiler will fill it for you.
	char myString[] = "Foo";
		//same as {'F', 'O', 'O', '\0'}
		//'\0' is a a null terminating character that specifies the end of a string (specifies the size of the string).
	
	//this is a c++ string
	string myName = "Foo";
	printf("%s \n", myString);

		//how do you turn c++ string to a c string?
		//by attaching a c_str.
	printf("%s \n", myName.c_str());

	//example with cstring width trick!
	//http://pastebin.com/9KRR29zP

	cout << "Please maximize the console size to fit bigger pyramids on it.\n";

	selectPyramidSize();

	if (pyramidSize > 136)
	{
		cout << "No larger than 136 because it won't fit on the console, try again.\n";
		selectPyramidSize();
	}

	int some = 1;
	int some2 = 0;
	int lineNumber = 1;
	for (int i = pyramidSize; i > 0; i -= 1)
	{
		if (lineNumber < 10)
		{
			cout << lineNumber << "   ";
		}
		else if (lineNumber < 100)
		{
			cout << lineNumber << "  ";
		}
		else if (lineNumber < 1000)
		{
			cout << lineNumber << " ";
		}

		printf("%*c", i, ' ');
		while (some > some2)
		{
			printf("%c", '.');
			some2++;
		}
		some += 2;
		some2 = 0;
		cout << '\n';
		lineNumber++;
	}


	system("PAUSE");
	return 0;
}

void selectPyramidSize()
{
	cout << "How big would you like the pyramid?\n";
	cin >> pyramidSize;
}