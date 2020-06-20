//inserting node at index n
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

struct Node* head;

void insertNode(int value, int n) {
	Node* newNode = new Node();

	newNode->data = value;
	newNode->next = NULL;

	if(n == 1) {
		newNode->next = head; 
		head = newNode;
		return;
	}

	Node* prevNode = head;
	for(int i = 0; i < (n-1)-1; i++) { //getting till (n-1)th element
		prevNode = prevNode-> next;
	}

	newNode->next = prevNode->next; 
	prevNode->next = newNode; //prev node pointing to new node
}

void print() {
	Node* temp = head;

	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

int main() {
	head = NULL;

	insertNode(2, 1); //base index is 1 not 0
	insertNode(3, 2);
	insertNode(4, 1);
	insertNode(5, 2);
	print();
}