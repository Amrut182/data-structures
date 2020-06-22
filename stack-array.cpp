//Stack using arrays 
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100

class Stack {
private:
	int A[MAX_SIZE];
	int top;

public:
	Stack() {
		top = -1;
	}

	void Push(int value) {
		if(top == MAX_SIZE - 1) {
			cout << "stack overflow" << "\n";
			return;
		}
		A[++top] = value;
	}

	void Pop() {
		if(top == -1) {
			cout << "stack is empty" << "\n";
			return;
		}
		top--;
	}

	int Top() {
		if(top == -1) {
			cout << "stack is empty" << "\n";
			return top;
		}
		return A[top];
	}

	bool isEmpty() {
		return (top == -1);
	}

	void Print() {
		for(int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
	}
};

int main() {
	Stack S;
	S.Push(2);
	S.Push(3);
	S.Push(9);
	S.Pop();
	S.Print();
	cout << S.Top() << " " << S.isEmpty() << "\n";
}