//stack implementation using linked list
//inserting at beginning of linked list
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Stack {
private:
	Node* top = NULL;

public:
	void Push(int value) {
		Node* newNode = new Node();
		newNode->data = value;

		if(top == NULL) {
			top = newNode;
			return;
		}
		
		newNode->next = top;
		top = newNode;
	}

	void Pop() {
		if(top == NULL) {
			cout << "stack empty \n";
			return;
		}

		Node* temp = top;
		top = temp->next;

		delete temp;
	}

	int Top() {
		if(top == NULL) return -1;

		return top->data;
	}

	bool isEmpty() {
		return !top;
	}	

	void Print() {
		if(top == NULL) return;

		Node* temp = top;

		while(temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << "\n";
	}
};

int main() {
	Stack S;
	S.Push(4);
	S.Push(5);
	S.Push(6);
	S.Push(9);
	S.Pop();
	S.Pop();
	S.Print();

	cout << S.Top() <<"\n";

	if(S.isEmpty()) cout << "stack is empty \n";
	else cout << "stack is not empty \n";
}

