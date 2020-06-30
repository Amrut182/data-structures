//printing nodes and reverse printing nodes using recursion
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* insert(Node* head, int value) {
	Node* newNode = new Node();

	newNode->data = value;
	newNode->next = NULL;

	if(head == NULL) {
		head = newNode;
	}
	else {
		Node* temp = head;

		while(temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newNode;
	}

	return head;
}

void print(Node* ptr) {
	if(ptr == NULL) {
		cout << "\n";
		return;
	}

	cout << ptr->data << " ";

	print(ptr->next);
}

void reversePrint(Node* ptr) {
	if(!ptr) {
		cout << "\n";
		return;
	}

	reversePrint(ptr->next);
	
	cout << ptr->data << " ";
}

int main() {
	Node* head = NULL;

	head = insert(head, 2);
	insert(head, 3);
	insert(head, 5);
	insert(head, 9);

	print(head);

	reversePrint(head);
}
