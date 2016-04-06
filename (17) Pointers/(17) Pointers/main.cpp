#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

void addOne(int *a);

int main() {

	//When we call this variable, we are allocating space in memory. (4 bytes) since it is an integer.
	int a = 5;
	int b = 10;
	// We can figure out where in the memory address it is going to be in.
	cout << &a << " " << &b <<endl;
	// it is indicated with a & just as a reference pass looks like but it is somewhat different.
	// this means we are getting the memory address of a.
	// this will return us the number that is the address of a.
	// the result will be a hexadecimal number. this is like the binary but instead of 2 it is based on 16.
	cout << (int)&a << " " << (int)&b << endl;
	// if you take the int of the hexadecimal, you get a number divisible by 4 and this is because an int is 4 bytes.
	// the variable b is allocated in memory right after a.
	// so b is 4 bytes after a.

	//So a pointer is a variable that stores an address.
	// this is an integer pointer. the * indicates it.
	int *myPointer = nullptr;
	// You always want to initialize a pointer. Null is good since if you try to access a null pointer the compiler will issue a null access violation. So it is easy to check for bugs.
	// If you dont initialize you may get a random address!

	// So again a pointer holds a memory address of a variable. Think of it as pointing to a location.
	// you can point at the variable by using an &.
	// and you can access the value it is pointing to by using the *.
	myPointer = &a;

	//So this will print out 5;
	cout << *myPointer << endl;
		// The & is called the reference operator and the * is called the dereference operator.
		// so since this is not creating another instance of a, but rather is pointing to the original value, if we change the value of a,
	a = 500;
	cout << *myPointer << endl;

	//we can utilize this instead of pass by reference.
	// using the addone function below,
	addOne(myPointer);

	cout << *myPointer << endl;
	// this should give us 501.
	// this is another way you can pass by reference.
	

	cout << "Enter any key to continue\n";
	int tmp;
	cin >> tmp;

	return 0;
}

void addOne(int *a) {
	*a += 1;
}

//Stack memory vs heap memory.
//	Out of the random access memeory, which is like a big array, or a big buffer, the variables we create are allocated in here somewhere.

//Stack
//	little segment of the program memory is the stack. Typically like a megabyte or so. The rest of the memory space is the heap.
//	The heap gets bigger or smaller as you add variables. Start out small, but grows when you add more variables.
//	When we create local variables, that will get allocated on the stack, and if you create global variables, it will get allocated on the static memory (same goes for other static variables).
//	The important aspect of the stack is that it lets us know where our program is and what is going on in the program.

// To elaborate, each function when called creates a frame on the stack (the frames stack on top of each other hence called the stack memory.)
// So for example, if we have a function outside of the main function that gets called in the main function, we have a main frame stack and the other fucntion stack.
// when the main function comes across a function call, the line number is kept in the main frame stack, and is indicated as a return address.
// The new function adds a new stack frame and when that function is finished, the stack frame of that function pops off and returns to the line number in the function it was originally in.
// Any local variables that were called in the other functions will have been deleted from the stack as the stack frame for that fuction has been deleted. (It has been de-allocated).
// Globals and static variables get stored in static memory which is similar to the heap memory, except that it is allocated for the entire lifetime of the program, whereas heap memory can be allocated with new and deallocated with delete.

//What is stack overflow???
//	Since there is a limited number of memory allocated to the stack, if you wanted to allocate something that is bigger than the size of the stack size, it
//	causes an error called stack overflow!