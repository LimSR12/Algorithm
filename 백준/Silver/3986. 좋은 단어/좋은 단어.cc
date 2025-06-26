#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;

    int count = 0;
    while (N--) {
        string str;
        cin >> str;

        stack<char> s;

        if (str.length() % 2 != 0) {
            continue;
        }

        for (int i = 0; i < str.length(); i++) {
            if (!s.empty()) { // 비어있지 않다면
                if (s.top() == str[i]) {
                    s.pop();
                }
                else {
                    s.push(str[i]);
                }
            }
            else { // 비어있다면
                s.push(str[i]);
            }
        }
        if (s.empty()) count++;
    }

    cout << count;

    return 0;
}