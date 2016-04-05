#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	//memset and memcopy

	//the variables we have used so far are..
	int a; //4 bytes
	char c; //1 byte = 8bits = 2^8 = -128~+128
	double d; //8 bytes
	float f; //4 bytes

	cout << "int is "  << sizeof(a) << " bytes" << endl;
	cout << "char is " << sizeof(c) << " bytes" << endl;
	cout << "double is " << sizeof(d) << " bytes" << endl;
	cout << "float is " << sizeof(f) << " bytes" << endl;

	//we can also get the size of an array but only if the array is declared in the same function we created or is a global array.
	int someBuffer[10];
	//buffer is basically an array or a buffered space in memory
	//keep in mind if you try to get the size of a buffer passed in by reference that would not necessarily be the actual size of the buffer.
	cout << sizeof(someBuffer) << endl;

	//memset function
		//good naming convention for a constant int is ALL CAP with underscore_between_words
	const int BUFFER_SIZE = 100;
	char myBuffer[BUFFER_SIZE];
	int myBuffer2[BUFFER_SIZE];
	int myBuffer3[BUFFER_SIZE];

	for (int i = 0; i < BUFFER_SIZE; i++) {
		cout << myBuffer[i];
		// this will output garbage literally since none of them have been set to anything and are just random.
	}
	cout << endl;
	// instead of using a for loop to set all of them to a value, we can use memset.
	// you need to pass in the buffersize as well. Best practice is to multiply the buffer_size by the size of the buffer's type
	memset(myBuffer, 'A', sizeof(char)*BUFFER_SIZE);
	memset(myBuffer2, 0, sizeof(int)*BUFFER_SIZE);
	memset(myBuffer3, 1, sizeof(int)*BUFFER_SIZE);
	// this is a faster way to allocate memory!
	for (int i = 0; i < BUFFER_SIZE; i++) {
		cout << myBuffer[i];
		// this will output all As
	}

	//memcopy function
	for (int i = 0; i < BUFFER_SIZE; i++) {
		cout << myBuffer2[i];
		// this will output all As
	}
	cout << endl;
	for (int i = 0; i < BUFFER_SIZE; i++) {
		cout << myBuffer3[i];
		// this will output all As
	}
	cout << endl;

		//THIS COPIES MYBUFFER 3 TO MYBUFFER 2.
	memcpy(myBuffer2, myBuffer3, sizeof(int)*BUFFER_SIZE);
	for (int i = 0; i < BUFFER_SIZE; i++) {
		cout << myBuffer2[i];
		// this will output all As
	}
	cout << endl;
	for (int i = 0; i < BUFFER_SIZE; i++) {
		cout << myBuffer3[i];
		// this will output all As
	}
	cout << endl;

	//better to use than system pause.
	printf("Enter any key to quit ...\n");
	int tmp;
	cin >> tmp;

	return 0;
}