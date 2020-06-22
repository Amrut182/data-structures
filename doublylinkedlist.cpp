//insert at tail, insert at head for doubly linked list
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

struct Node* head;

Node* getNewNode(int x) {
	Node* newNode = new Node();

	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void insertAtHead(int value) {
	Node* newNode = getNewNode(value);

	if(head == NULL) {
		head = newNode;
		return;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void insertAtTail(int value) {
	Node* newNode = getNewNode(value);

	if(head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;

	while(temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;
}

void print() {
	Node* temp = head;

	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << "\n";
}

void reversePrint() {
	Node* temp = head;

	while(temp->next != NULL) {
		temp = temp->next;
	}

	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	
	cout << "\n";
}

int main() {
	insertAtHead(2);
	insertAtHead(3);
	insertAtHead(5);
	insertAtHead(7);
	insertAtTail(25);

	print();
	reversePrint();
}