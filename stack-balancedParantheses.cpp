#include<bits/stdc++.h>
using namespace std;

bool paired(char open, char close) {
	if(open == '(' && close == ')') return true;
	else if(open == '{' && close == '}') return true;
	else if(open == '[' && close == ']') return true;
	else return false;
}

bool balancedParantheses(string str) {
	stack<char> s;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == '{' || str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
		}
		else if(str[i] == '}' || str[i] == '}' || str[i] == ']') {
			if(s.empty() || !paired(s.top(), str[i])) {
				return false;
			}
			else {
				s.pop();
			}
		}
	}
	return s.empty();
}

int main() {
	string str = "{[}]";
	if(balancedParantheses(str)) {
		cout << "balanced\n";
	} else {
		cout << "not balanced\n";
	}
}