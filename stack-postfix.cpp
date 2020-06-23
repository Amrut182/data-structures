//evaluating postfix using stack
//only works with single digit as operands
#include<bits/stdc++.h>
using namespace std;

bool isOperand(char a) {
	return isdigit(a);
}

bool isOperator(char a) {
	if(a == '+' || a == '-' || a == '*' || a == '/') {
		return true;
	} 
	return false;
}

int evaluate(char oper, char op1, char op2) {
	switch(oper) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
	}
}

int main() {
	string str = "2 3 * 5 4 * +";
	cout << str << "\n";
	stack<int> s;

	for(int i = 0; i < str.length(); i++) {
		if(str[i] == ' ') continue;
		else if(isOperand(str[i])) {
			 s.push(str[i] - '0');
		}
		else if(isOperator(str[i])) {
			int operand2 = s.top(); s.pop();
			int operand1 = s.top(); s.pop();
			int result = evaluate(str[i], operand1, operand2);
			s.push(result);
		}
	}
	cout << "result is: " << s.top() << "\n" ;
}