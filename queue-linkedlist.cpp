//queue implementation using linked list
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedList {
private: 
	Node* front = NULL;
	Node* rear = NULL;

public:
	void Enqueue(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		if(front == NULL && rear == NULL) { //insertion into empty list
			front = newNode;
			rear = newNode;
			return;
		}
		rear->next = newNode;
		rear = newNode;
	} 

	void Dequeue() {
		if(front != NULL) {
			Node* temp = front;
			front = front->next;
			delete temp;
		} else {
			cout << "queue empty";
			return;
		}
	}

	int Front() {
		if(front != NULL) {
			return front->data;
		} else return -1;

	}

	void Print() {
		Node* temp = front;
		while(temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
};

int main() {
	LinkedList L;
	L.Enqueue(2);
	L.Enqueue(5);
	L.Enqueue(12);
	L.Enqueue(7);
	L.Dequeue();
	L.Dequeue();
	L.Print();
	cout << "front element is: " << L.Front() << endl;
}