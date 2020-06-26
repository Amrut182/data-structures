//level order traversal for BST
#include<bits/stdc++.h>
using namespace std;

struct BSTNode {
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
		if(root == NULL) {
			root = getNode(value);
			return root;
		} 
		else if(value <= root->data) {
			root->left = insert(root->left, value);
		}
		else {
			root->right = insert(root->right, value);
		}
		return root;
	}

	void levelOrder(BSTNode* root) {
		if(root == NULL) return;
		queue<BSTNode*> q;
		q.push(root);
		while(!q.empty()) {
			BSTNode* temp = q.front();
			cout << temp->data << " ";
			if(temp->left != NULL) q.push(temp->left);
			if(temp->right != NULL) q.push(temp->right);
			q.pop();
		}
	}

};

int main() {
	BST T;

	root = T.insert(root, 3);
	root = T.insert(root, 5);
	root = T.insert(root, 1);
	root = T.insert(root, 7);
	root = T.insert(root, 18);
	root = T.insert(root, 6);

	T.levelOrder(root);
}