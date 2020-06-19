#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void printList(Node *n) {
	while(n) { //n != NULL
		cout << n->data << endl;
		n = n->next;
	}
}

int main() {
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	//allocating 3 nodes in heap
	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 4;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 6;
	third->next = NULL;

	printList(head);
}