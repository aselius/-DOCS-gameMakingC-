#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void byReference(int &a);
void byReferencePointer(int *a);

int main() {
	// How to allocate things in the heap without making global variables.
	// When we create pointers, we can do so by setting them to nullptr or set them to a memory address of a value in the heap.
		// TO DO THIS: we use the new operator.

	int *myPointer = nullptr;
	int *myPointer2 = nullptr;

	myPointer = new int[10000];
	myPointer2 = new int;
	// When the stack for a function using new operator disappears, the pointer to the memory address disappears, however, the value changed is not affected.
	// Howver since the pointer that was pointing to that specific value has disappeared there is no way to access that variable in the heap.
	// This is called a Memory leak!!
	// So you need to make sure that you delete the variable.
	delete[] myPointer;
	delete myPointer2;
	// the delete operator is delete for variables and delete[] for arrays.
	// When you perform this delete you are still left with a pointer pointing to an empty value. So we can set it to a null pointer.
	myPointer = nullptr;

	// **Number of deletes should always be equal to the number of news.**
	// Dont double delete!

	cout << "Enter any key to continue...\n";
	int tmp;
	cin >> tmp;
	return 0;
}

// Difference between pass by reference and pass by reference pointer
	// They essentially do the same thing but with the pass in pointer,
	// you can do somethiing like pass in a nullpointer
	// This will give you a null access violation, but with the pass by reference you can't pass in a pointer, only a variable.
	
void byReference(int &a) {
	a += 5;
}

void byReferencePointer(int *a) {
	*a += 5;
}