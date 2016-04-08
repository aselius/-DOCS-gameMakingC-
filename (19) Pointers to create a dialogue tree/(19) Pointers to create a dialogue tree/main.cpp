#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include "DialogueTree.h"

using namespace std;

// We want to create a dialogue tree where there are different choices for different dialogues


int main() {

	DialogueTree dialogueTree;

	dialogueTree.init();
	int rv = dialogueTree.performDialogue();

	if (rv == 1) {
		cout << "\nYou accepted the quest!\n";
	}

	dialogueTree.destroyTree();

	cout << "Enter any key to continue.... \n";
	int tmp;
	cin >> tmp;
	return 0;
}