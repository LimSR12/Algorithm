#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void DFS(int x, int y, vector<vector<int>>& field, vector<vector<int>>& check) {
	// field[x][y] == 1 && check[x][y] == 0 싹 탐색
	if (field[x][y] == 0) {
		return;
	}
	check[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < field.size() && 
			next_y >= 0 && next_y < field[0].size() &&
			field[next_x][next_y] == 1 &&
			check[next_x][next_y] == 0) {
			DFS(next_x, next_y, field, check);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, M, N, K, X, Y;

	cin >> T;

	while(T--) {
		// 각 테스트 케이스
		cin >> M >> N >> K;
		vector<vector<int>> field(M, vector<int>(N, 0));	// 밭
		vector<vector<int>> check(M, vector<int>(N, 0));	// 탐색한 위치 체크

		for (int i = 0; i < K; i++) {
			// 배추 위치
			cin >> X >> Y;
			field[X][Y] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == 1 && check[i][j] == 0) {
					DFS(i, j, field, check);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}