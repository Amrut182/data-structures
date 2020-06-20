#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

struct Node* head;

void insert(int value) { //inserts node at beginning
	Node* newNode = new Node();

	newNode->data = value;
	newNode->next = head;

	head = newNode;
}

void deleteNode(int n) {
	Node* temp = head;
	if(n == 1){
		head = temp->next;
		delete(temp);
		return;
	}
	for(int i = 0; i < (n-1)-1; i++) { //getting (n-1)th node
		temp = temp->next;
	}

	Node* node_n = temp->next; //nth node
	temp->next = node_n->next; //setting address of (n-1)th node to that of (n+1)th node
	delete node_n;
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
	head = NULL; //empty list
	int n;

	insert(2);
	insert(4);
	insert(6);
	insert(5);
	print();

	cout << "enter position to delete \n";
	cin >> n;

	deleteNode(n);
	print();
}