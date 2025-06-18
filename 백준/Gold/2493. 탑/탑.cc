#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	
	int N;
	cin >> N;

	vector<int> heights(N + 1);
	vector<int> answer(N + 1);
	stack<pair<int, int>> s; // {index, height}
	
    for (int i = 1; i <= N; i++) {
        cin >> heights[i];

        // 스택에서 현재 탑보다 낮은 탑은 제거
        while (!s.empty() && s.top().second < heights[i]) {
            s.pop();
        }

        if (!s.empty()) {
            answer[i] = s.top().first;
        }
        else {
            answer[i] = 0;
        }

        s.push({ i, heights[i] });
    }

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << " ";
    }


	return 0;
}