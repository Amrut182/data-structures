//Linked list with 3 nodes
//Printing the values of 3 nodes
//Printing the value of node at given index
//Printing the index of given value after searching
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void printList(Node *n) {
	while(n) { //n != NULL
		cout << n -> data << endl;
		n = n -> next;
	}
}

void printValueAtIndex(Node *n, int index) {
	while(index--) {
		n = n -> next;
	}
	cout << n -> data << endl;
}

void searchNode(Node *n, int value) {
	int count = 0;
	while(n) {
		if(value == n -> data) {
			cout << "found at index " << count << endl;
			return;
		}
		n = n -> next;
		count++;
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

	head -> data = 1;
	head -> next = second;

	second -> data = 2;
	second -> next = third;

	third -> data = 3 ;
	third -> next = NULL;

	printList(head);
	printValueAtIndex(head, 0);
	searchNode(head, 1);
}