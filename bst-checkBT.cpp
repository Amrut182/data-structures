//check if bt is bst
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* root = NULL;

Node* getNode(int value) {
	Node* newNode = new Node();
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

bool checkBST(Node* root, int Min, int Max ) {
	if(root == NULL) {
		return true;
	}
	if(root->data > Min && root->data < Max && checkBST(root->left, Min, root->data) 
		&& checkBST(root->right, root->data, Max)) {
		return true;
	} else {
		return false;
	}
}

struct Node* newNode(int data) 
{ 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 

int main() {

	Node *root = getNode(3); 
    root->left = getNode(2); 
    root->right = getNode(5); 
    root->left->left = getNode(1); 
    root->left->right = getNode(4); 

	if(checkBST(root, INT_MIN, INT_MAX)) {
		cout << "bt is BST" << "\n";
	} else {
		cout << "bt is not BST" << "\n";
	}
}