#include <iostream>
using namespace std;

int N, M;
int arr[10];       // 현재까지 선택한 수열
bool used[10];     // 사용 여부

void backtrack(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            arr[depth] = i;
            used[i] = true;
            backtrack(depth + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    backtrack(0);
    return 0;
}
