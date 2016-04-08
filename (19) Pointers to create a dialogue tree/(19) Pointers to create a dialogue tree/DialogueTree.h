#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class DialogueNode;

class DialogueOption {
public:
	DialogueOption(string Text, int ReturnCode, DialogueNode *NextNode);

	string text;
	DialogueNode *nextNode;
	int returnCode;
};

class DialogueNode {
public:
	DialogueNode(string Text);

	string text;
	vector <DialogueOption> dialogueOptions;
};

class DialogueTree
{
public:
	DialogueTree();

	void init();
	void destroyTree();
	
	int performDialogue();

private:
	vector <DialogueNode *> dialogueNodes;
};

