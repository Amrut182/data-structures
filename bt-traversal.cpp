//preorder, inorder, postorder traversal in binary tree 
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
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insert(Node* root, int value) {
	if(root == NULL) {
		root = getNode(value);
	}
	else if(value <= root->data) {
		root->left = insert(root->left, value);
	}
	else {
		root->right = insert(root->right, value);
	}
	return root;
}

void preorder(Node* root) {
	if(root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(Node* root) {
	if(root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

/*
Tree : 			3
               / \
              1   7
                 / \
                4  17
*/			
int main() {
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 7);
	root = insert(root, 4);
	root = insert(root, 17);

	cout << "preorder: ";
	preorder(root);
	cout << "\n";

	cout << "inorder: ";
	inorder(root);
	cout << "\n";

	cout << "postorder: ";
	postorder(root);
	cout << "\n";
}