#include <iostream>
#include <vector>
#include <string>

using namespace std;

void flip(vector<vector<int>>& A, int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            A[i][j] = 1 - A[i][j];
        }
    }
}

int main() {
    
    int N, M;

    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M, 0));
    vector<vector<int>> B(N, vector<int>(M, 0));

    // A 입력
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            A[i][j] = s[j] - '0';
        }
    }

    // B 입력
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            B[i][j] = s[j] - '0';
        }
    }

    // A != B 일 경우 A의 해당 인덱스 왼쪽 위를 기준으로 뒤집음
    int count = 0;
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if (A[i][j] != B[i][j]) {
                flip(A, i, j);
                count++;
            }
        }
    }

    if (A == B) {
        cout << count << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}