#include <iostream>
#include <string>

using namespace std;

//Functions are what make code modular if you will. So you can call a function to perform the same action twice or more by calling the function multiple times!
//For C++, functions are indicated with a return value. This main function has the return value type of 'integer'
//So if you recall the challenge we did just before, we had a part of the main code where we asked the user to input the number of humans and skeletons. For that we can
//	write new functions to substitute the lines of code that were responsible for that task.

int getNumberHumans() {
	//So this would be a function with a return value of int.
	//We need to pay attention to whats called a scope. Scope is what variables the function has access to.
	//This function will not have any access to the variables called in other functions. Just the ones called in this function and global variables.
	int humans;
	cout << "Enter the Number of Humans: ";
	cin >> humans;
	return humans;
}

int getNumberSkeletons() {
	int skeletons;
	cout << "Enter the Number of Skeletons: ";
	cin >> skeletons;
	return skeletons;
}

int main() {
	//This is the same work flow we used in the challenge. But instead of having everything in one main function we separated it into little functions.
	int numberHumans, numberSkeletons = 0;
	
	//This is the function call. Function calls have () next to the function name to invoke the function.
	numberHumans = getNumberHumans();
	//Remember return values? The returned value is being saved into the integer variable numberHumans.
	numberSkeletons = getNumberSkeletons();
	//So forth to numberSkeletons.

	cout << "There are " << numberHumans << " Humans and " << numberSkeletons << " Skeletons in this game!\n";
	//So now, the number we entered in other functions are in the main function!
	system("PAUSE");
	return 0;
}

//Forward declaration: Notice how the other functions are called before the main? 
//	This is because it does not recognize theses as functions.
//	This can be solved by forward declarations.
//	You declare the function before the main!
//		eg. int getNumberHumans()
//	Put this before the main function and place the action function after the main function.