//deleting node from a tree
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* root = NULL;

Node* getNode(Node* root, int value) {
	Node* newNode = new Node();
	newNode->data = value;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

Node* insert(Node* root, int value) {
	if(root == NULL) {
		root = getNode(root, value);
	}
	else if(value <= root->data) {
		root->left = insert(root->left, value);
	}
	else {
		root->right = insert(root->right, value);
	}
	return root;
}

Node* findMin(Node* root) {
	Node* temp = root;
	while(root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* Delete(Node* root, int value) {
	if(root == NULL) {
		return root;
	}
	else if(value < root->data) {
		root->left = Delete(root->left, value);
	}
	else if(value > root->data) {
		root->right = Delete(root->right, value);
	}
	else {
		//No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
			return root;
		}
		//having right child
		else if(root->left == NULL) {
			Node* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		//having left child 
		else if(root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp; 
			return root;
		}
		//having both child
		else {
			Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, value);
			return root;
		}
	}
}

void inorder(Node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
	root = insert(root, 14);
	root = insert(root, 18);
	root = insert(root, 11);
	root = insert(root, 20);
	inorder(root);
	cout << "\n";
	Delete(root, 11);
	inorder(root);
}