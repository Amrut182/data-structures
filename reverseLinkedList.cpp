//reverse linked list iteratively
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* insert(Node* head, int value) { //inserting at end
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

Node* reverse(Node* head) {
	Node *curr, *prev, *next;

	curr = head;
	prev = NULL;

	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;

	return head;
}

void print(Node* head) {
	Node* temp = head;

	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << "\n";
}

int main() {
	Node* head = NULL; //empty list

	head = insert(head, 2);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 8);

	print(head);

	head = reverse(head);
	print(head);
}