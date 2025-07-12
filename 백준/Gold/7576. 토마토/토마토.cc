#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>

// 위, 아래, 오른쪽, 왼쪽
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

using namespace std;

void BFS(vector<vector<int>>& storage, vector<vector<int>>& days, int N, int M) {
    
    queue<pair<int, int>> q;
    
    // 초기 익은 토마토 인덱스 찾아서 큐에 push
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (days[i][j] == 1) {
                q.push({ i, j });
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> pos = q.front(); q.pop();
        int x = pos.first;
        int y = pos.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;   // 인덱스 범위 체크
            if (storage[nx][ny] != 0) continue;                     // 0이 아니라면 토마토가 익었거나 없거나
            
            storage[nx][ny] = 1;
            days[nx][ny] = days[x][y] + 1;
            q.push({ nx, ny });
        }
    }
}

int main() {

    int dayCount = 0;
    int M, N; // M : 가로, N : 세로
    cin >> M >> N;

    vector<vector<int>> storage(N, vector<int>(M, 0));
    vector<vector<int>> days(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> storage[i][j];
        }
    }

    // 1. 초기에 주어진 storage에서 값이 1인 인덱스 전부 찾아서 저장 (days[N][M])
    // 2. BFS함수 호출, days[i][j] == 1이면 전부 q.push()
    // 3. q가 빌때까지 반복하면서, q.front()로 받은 인덱스에 대해 상하좌우 퍼져나가고, 새로 퍼져나간 인덱스 q.push()
    // 4. q가 비었다면 종료하고, 0이 남아있다면 -1, 전부 1이 되었다면 count 출력
    // 시간복잡도는? O(n * M)

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (storage[i][j] == 1) {
                days[i][j] = 1;
            }
        }
    }

    BFS(storage, days, N, M);
    
    int maxDay = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (storage[i][j] == 0) {
                cout << -1;
                return 0;
            }
            maxDay = max(maxDay, days[i][j]);
        }
    }
    cout << maxDay - 1;

    /*cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << days[i][j] << " ";
        }
        cout << "\n";
    }*/

    
    return 0;
}