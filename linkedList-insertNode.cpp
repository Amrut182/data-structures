//inserting nodes at beginning
#include<bits/stdc++.h>
using namespace std;

struct  Node{
	int data; 
	Node *next; //struct Node* next; (for c)
};

struct Node* head; //globally declared

void Insert(int x) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->next = head; //when empty, head is NULL
	head = temp; //head pointing to temp node, head stores address of temp
}

void Print() {
	Node* temp = head;
	cout << "List: ";
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

int main() {
	head = NULL; //empty list

	int n, x;
	cout << "how many numbers \n";
	cin >> n;

	for(int i = 0; i < n; i++) {
		cout << "enter no. \n";
		cin >> x;
		Insert(x);
		Print();
	}
}