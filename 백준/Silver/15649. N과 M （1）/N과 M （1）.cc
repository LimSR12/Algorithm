#include <iostream>

using namespace std;

static bool V[8];
static int S[8];
static int N, M;

void backtracking(int length) {
	if (length == M) {
		for (int i = 0; i < M; i++) {
			cout << S[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!V[i]) {
			V[i] = true;
			S[length] = i + 1;
			backtracking(length + 1);
			V[i] = false;
		}
	}
}


int main() {
	cin >> N >> M;
	backtracking(0);
	return 0;
}