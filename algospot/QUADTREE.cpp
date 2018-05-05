#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Node{
public:
	char value;
	Node *children[4];
};

int order[4] = { 2, 3, 0, 1 };

string createNode(Node* node, string input) {
	
	node->value = input[0];
	input = input.substr(1);
	if (node->value != 'x')
		return input;

	for (int i = 0; i < 4; i++) {
		int numOfChildren;
		node->children[i] = new Node();
		input = createNode(node->children[i], input);
	}

	return input;
}

Node* input() {
	
	string inputString;
	cin >> inputString;

	Node root;
	createNode(&root, inputString);		

	return &root;
}

void solve(Node node) {
	printf("%c", node.value);
	if (node.value != 'x')
		return;
	for (int i = 0; i < 4; i++)
		solve(*node.children[order[i]]);
	
}

int main()
{
	int numberOfTestCase;
	scanf("%d", &numberOfTestCase);
	
	for (int i = 0; i < numberOfTestCase; i++) {
		Node *root = input();
		solve(*root);
		printf("\n");
	}
	return 0;
}
