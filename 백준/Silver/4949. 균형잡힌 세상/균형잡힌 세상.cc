#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	
	while (true) {
		stack<char> s;
		string line;
		int isbalanced = 1;

		getline(cin, line);

		if (line == ".") {
			break;
		}
		
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '(' || line[i] == '[') {
				s.push(line[i]);
			}
			else if (line[i] == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					isbalanced = 0;
				}
			}
			else if (line[i] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					isbalanced = 0;
				}
			}
		}

		if (isbalanced && s.empty()) {
			cout << "yes" << '\n'; 
		}
		else {
			cout << "no" << '\n';
		}
	}

	return 0;
}