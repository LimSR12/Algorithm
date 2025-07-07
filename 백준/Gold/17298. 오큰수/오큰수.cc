#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> answer(N, -1);
    stack<int> s;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        // top의 오큰수가 arr[i]인지 확인 후, 맞다면 pop 하고 그 다음 top의 오큰수인지도 반복해서 확인
        while (!s.empty() && arr[s.top()] < arr[i]) {
            answer[s.top()] = arr[i];
            s.pop();
        }
        s.push(i); // arr[i] 도 오큰수를 찾을 수 있도록 스택에 push
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }
    
    return 0;
}