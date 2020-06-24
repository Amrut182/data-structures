//implementing queue using circular array
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 20

class Queue {
private:
	int A[MAX_SIZE];
	int rear;
	int front;

public:
	Queue() {
		front = rear = -1;
	}

	void Enqueue(int value) {
		if(isFull()) {
			cout << "Queue full \n";
			return;
		}
		if(isEmpty()) {
			front = 0;
			rear = 0;
		}
		else {
			rear = (rear + 1)%MAX_SIZE;
		}
		A[rear] = value;
	}

	void Dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty\n";
			return;
		}
		front = (front + 1)%MAX_SIZE;
	}

	bool isEmpty() {
		return (front == -1 && rear == -1);
	};

	bool isFull() {
		return ((rear + 1)%MAX_SIZE == front);
	}

	int Front() {
		if(isEmpty()) {
			return -1;
		}
		return A[front];
	}

	void Print() {
		for(int i = front; i <= rear; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
	}
};

int main() {
	Queue Q;
	Q.Enqueue(3);
	Q.Enqueue(2);
	Q.Enqueue(5);
	Q.Dequeue();
	Q.Print();
	cout << "front element is: " << Q.Front() << endl;
}