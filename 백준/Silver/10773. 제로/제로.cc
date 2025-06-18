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

	int K;
	stack<int> s;

	cin >> K;

	while (K--) {
		int num;
		cin >> num;

		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}
	
	int total = 0;
	while (!s.empty()) {
		total += s.top();
		s.pop();
	}
	
	cout << total;

	return 0;
}