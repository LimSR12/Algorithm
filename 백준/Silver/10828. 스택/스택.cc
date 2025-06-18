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

	int N;
	stack<int> s;
	cin >> N;
	while (N--) {
		string cmd;
		int num;

		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			s.push(num);
		}
		if (cmd == "pop") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << s.top() << "\n";
			s.pop();
		}
		if (cmd == "size") {
			cout << s.size() << "\n";
		}
		if (cmd == "empty") {
			cout << (s.empty() ? 1 : 0) << "\n";
		}
		if (cmd == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << s.top() << "\n";
		}
	}

	return 0;
}