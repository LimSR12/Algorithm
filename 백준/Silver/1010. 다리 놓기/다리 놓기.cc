#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <ctime>

using namespace std;

unsigned long long combination(int n, int r) {
	if (r > n - r) {
		r = n - r; // 대칭성 nCr == nC(n-r)
	}
	unsigned long long result = 1;
	for (int i = 1; i <= r; ++i) {
		result *= n - r + i;
		result /= i;
	}
	return result;
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;	
		cout << combination(M, N) << '\n';
	}

	return 0;
}