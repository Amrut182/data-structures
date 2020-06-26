//finding height of BST using recursion
#include<bits/stdc++.h>
using namespace std;

struct BSTNode{
	int data;
	BSTNode* left;
	BSTNode* right;
};


BSTNode* root;

class BST {
public:
	BST() {
		root = NULL;
	}

	BSTNode* getNode(int value) {
		BSTNode* newNode = new BSTNode();
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	BSTNode* insert(BSTNode* root, int value) {
		BSTNode* newNode = getNode(value);
		if(root == NULL) {
			root = newNode;
		}
		else if(value <= root->data) {
			root->left = insert(root->left, value);
		}
		else if(value > root->data) {
			root->right = insert(root->right, value);
		}
		return root;
	}

	bool search(BSTNode* root, int value) {
		if(root == NULL) {
			return false;
		}
		else if(root->data == value) {
			return true;
		}
		else if(root->data >= value) {
			return search(root->left, value);
		}
		else {
			return search(root->right, value);
		}
	}

	int findHeight(BSTNode* root) {
		if(root == NULL) {
			return -1;
		}
		int leftHeight = findHeight(root->left);
		int rightHeight = findHeight(root->right);
		return max(leftHeight, rightHeight) + 1;
  	}
};

int main() {
	BST T;
	root = T.insert(root, 3);
	root = T.insert(root, 2);
	root = T.insert(root, 6);
	root = T.insert(root, 12);
	root = T.insert(root, 15);

	if(T.search(root, 12)) {
		cout << "element found\n";
	} else {
		cout << "not found\n";
	}
	cout << "Height of BST is : " << T.findHeight(root) << "\n";
}