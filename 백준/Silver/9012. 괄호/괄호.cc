#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		string str;
		stack<char> s;

		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				s.push(str[i]);
			}
			else {
				if (!s.empty() && s.top() == '(') { // 스택이 비어있을때 s.top() 호출하면 Expression: back() called on empty deque 에러 !!
					s.pop();
				}
				else {
					s.push(str[i]);
				}
			}
		}
		
		cout << (s.empty() ? "YES\n" : "NO\n");
	}

	return 0;
}