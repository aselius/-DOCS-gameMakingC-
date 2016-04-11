#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

#include "Zombie.h";

using namespace std;

void myFunction(int *myArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << myArray[i] << endl;
	}
}

int main() {

	int input;
	cin >> input;

	//if you are using an array you need to put a constant int as its size
	//and can't use a nonconstant input.
	int myArray[1000];

	//However with a pointer we can do so. This is called a dynamic array.
	int *myArray2 = new int[input];
	//Since we are using a new command to allocate space in the heap we need to delete. This is done wity delete[]

	for (int i = 0; i < input; i++) {
		//when you call the elements in the array like this, it is accessing the point it is pointing to and increase it
		// by however many bytes that variable is so i, i+4 and so on and the compiler fetches the value using this repeated
		// gets. also you do not need a dereferencing operator * since you are using [] which dereferences.
		myArray2[i] = i;
			//this is like saying *myArray + how ever many bytes after the first.
	}

	myFunction(myArray2, input);
	//When we try to pass in a dynamic array, this is how you would pass them in.
	//pointers and arrays are very alike.
	
	delete[] myArray2;

	//if we create a zombie class as such, we need to remember to destruct the zombie as well.
	//using delete calls the destructor
	Zombie *myZombie = new Zombie;

	delete myZombie;



	int tmp;
	cin >> tmp;
	return 0;
}