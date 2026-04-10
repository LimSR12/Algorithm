#include <iostream>
#include <cmath>

using namespace std;

int N;
int ans = 0;
int queen[15]; // queen[row] = col

// 현재 row 에 퀸을 놓을 수 있는지 확인
bool isValid(int row, int col) {
	for (int r = 0; r < row; r++) {
		if (queen[r] == col) return false; // 같은 열 체크
		if (abs(queen[r] - col) == abs(r - row)) return false; // 대각선 체크
	}
	return true;
}

void backtrack(int row) {
	if (row == N) {
		ans++;
		return;
	}

	for (int col = 0; col < N; col++) {
		if (!isValid(row, col)) continue;
		queen[row] = col;
		backtrack(row + 1);
	}
}

int main() {
	cin >> N;
	backtrack(0);
    cout << ans << "\n";
	return 0;
}