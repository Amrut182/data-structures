//reverse a string using stack
#include<bits/stdc++.h>
using namespace std;

void reverseString(char A[], int size) {
	stack<char> s;
	for(int i = 0; i < size - 1; i++) {
		s.push(A[i]);
	}
	for(int i = 0; i < size-1; i++) {
		A[i] = s.top();
		s.pop();
	}
}

int main() {
	char s[50];
	cout << "enter string: ";
	fgets(s, 50, stdin);
	int size = strlen(s);
	reverseString(s, size);
	cout << "reversed string: " << s ;
}