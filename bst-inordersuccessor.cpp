//finding inorder successor of element in tree
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
	newNode->left = NULL;
	newNode->right = NULL;
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

Node* search(Node* root, int value) {
	if(root == NULL) {
		return root;
	}
	else if(root->data == value) return root;
	else if(value < root->data) return search(root->left, value);
	else return search(root->right, value);
}

Node* findMin(Node* root) {
	Node* temp = root;
	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

Node* inorderSuccessor(Node* root, int value) {
	Node* current = search(root, value);
	if(current == NULL) return current;
	//when node has right subtree
	if(current->right != NULL) {
		return findMin(current->right);
	} 
	//when node has no right subtree
	else {	
		Node* successor = NULL;
		Node* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return successor;
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
	root = insert(root, 5);
	root = insert(root, 7);
	root = insert(root, 3);
	root = insert(root, 9);
	inorder(root);
	cout << "\n";
	int successor = (inorderSuccessor(root, 7))->data;
	cout << successor << "\n";
}