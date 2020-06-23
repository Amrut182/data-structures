//reverse a linked list using stack
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};


class Linkedlist {
private:
	Node* head = NULL;
	stack<struct Node*> s;

public:
	void insert(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		if(head == NULL) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	void pushToStack() {
		Node* temp = head;
		while(temp != NULL) {
			s.push(temp);
			temp = temp->next;
		}
	}

	void reverse() {
		pushToStack();
		Node* temp = s.top();
		head = temp;
		s.pop();
		while(!s.empty()) {
			temp->next = s.top();
			s.pop();
			temp = temp->next;
		}
		temp->next = NULL;
	}
	
	void print() {
		Node* temp = head;
		while(temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
};


int main() {
	Linkedlist l;
	l.insert(3);
	l.insert(8);
	l.insert(4);
	l.insert(1);
	l.print();
	l.reverse();
	l.print();
}