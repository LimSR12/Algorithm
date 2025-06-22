#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;

    int N;
    cin >> N;

    while (N--) {
        int cmd;
        cin >> cmd;

        switch (cmd) {
        case 1:
            int x;
            cin >> x;
            s.push(x);
            break;
        case 2:
            if (s.empty()) {
                cout << -1 << '\n';
                break;
            }
            cout << s.top() << '\n';
            s.pop();
            break;
        case 3:
            cout << s.size() << '\n';
            break;
        case 4:
            if (s.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
            break;
        case 5:
            if (s.empty()) {
                cout << -1 << '\n';
                break;
            }
            cout << s.top() << '\n';
            break;
        }
    }


    return 0;
}