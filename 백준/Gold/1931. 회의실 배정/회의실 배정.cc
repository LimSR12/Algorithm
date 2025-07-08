#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<pair<int, int>> table;
    stack <pair<int, int>> s;

    for(int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;

        table.push_back({ start, end });
    }

    //for (int i = 0; i < N; i++) {
    //    s.push({ table[i].first, table[i].second });
    //    // i 이외의 인덱스를 돌면서(table[j]). table[j] >= s.top().second이면 push 하는걸로 해야하나?
    //    // 이 방법은 시간초과 가능성!
    //    // 회의 수가 많아지면 시간복잡도 n의 제곱으로 늘어남
    //}

    sort(table.begin(), table.end(), [](auto& a, auto& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int lastEnd = 0;
    int count = 0;

    for (auto& schedule : table) {
        if (schedule.first >= lastEnd) {
            lastEnd = schedule.second;
            count++;
        }
    }
    cout << count;
    
    return 0;
}