#include "DialogueTree.h"

DialogueOption::DialogueOption(string Text, int ReturnCode, DialogueNode *NextNode) {
	text = Text;
	returnCode = ReturnCode;
	nextNode = NextNode;
}

DialogueNode::DialogueNode(string Text) {
	text = Text;
}

DialogueTree::DialogueTree(){

}

void DialogueTree::init() {
	DialogueNode *node0 = new DialogueNode("Hello Brave Warrior!");
	DialogueNode *node1 = new DialogueNode("I don't want to talk to you.");
	DialogueNode *node2 = new DialogueNode("I have a quest for you!");
	DialogueNode *node3 = new DialogueNode("You will get 5 gold you greedy swine.");
	DialogueNode *node4 = new DialogueNode("Collect ten dandilions.");

	// when you declare a pointer using the *variable syntax, if you call the variable with just
	// its name, you get the memory address of the variable. You need to use the dereference operator
	// * before the variable name in order to obtain the variable.
	// so here on the next line, we need to use (*node0) or in short node0->
	node0->dialogueOptions.push_back(DialogueOption("Sup Noob!", 0, node1));
	node0->dialogueOptions.push_back(DialogueOption("Hello Strange Voice!", 0, node2));
	dialogueNodes.push_back(node0);
	// we need to push the nodes back to the dialogues since the node0 etc we created above are
	// in the stack (not the variables that we pushed to the heap but the memory address we are holding here)
	// and the memory address will get lost which means there would be no way to access the variable we allocated
	// on the stack. This will cause a memory leak!
	node1->dialogueOptions.push_back(DialogueOption("Aww..", 0, nullptr));
	dialogueNodes.push_back(node1);

	node2->dialogueOptions.push_back(DialogueOption("K Bye.", 0, nullptr));
	node2->dialogueOptions.push_back(DialogueOption("What's the pay?", 0, node3));
	node2->dialogueOptions.push_back(DialogueOption("What is it?", 0, node4));
	dialogueNodes.push_back(node2);

	node3->dialogueOptions.push_back(DialogueOption("Ok, what is it?", 0, node4));
	node3->dialogueOptions.push_back(DialogueOption("That sucks, I'm out.", 0, nullptr));
	dialogueNodes.push_back(node3);

	node4->dialogueOptions.push_back(DialogueOption("Let's Do it!", 1, nullptr));
	node4->dialogueOptions.push_back(DialogueOption("No way.", 0, nullptr));
	dialogueNodes.push_back(node4);
}

void DialogueTree::destroyTree() {
	for (int i = 0; i < dialogueNodes.size(); i++) {
		//This releases the heap memory!
		delete dialogueNodes[i];
	}
	//This releases the stack memory (if not already done so)
	dialogueNodes.clear();
}

int DialogueTree::performDialogue() {
	//empty() is equivalent to .size() == 0
	if (dialogueNodes.empty()) {
		return -1;
	}

	DialogueNode *currentNode = dialogueNodes[0];

	while (true) {

		cout << currentNode->text << "\n\n";

		for (int i = 0; i < currentNode->dialogueOptions.size(); i++) {
			cout << i + 1 << ": " << currentNode->dialogueOptions[i].text << endl;
		}
		cout << endl;
		int input;
		cin >> input;
		input--;

		if (input <0 || input > currentNode->dialogueOptions.size()) {
			cout << "Invalid Input!\n";
		}
		else {
			//Check for end of conversation.
			if (currentNode->dialogueOptions[input].nextNode == nullptr) {
				return currentNode->dialogueOptions[input].returnCode;
			}
			currentNode = currentNode->dialogueOptions[input].nextNode;
			
		}
		cout << endl;
	}
}
