#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <climits>

using namespace std;

int main() {
    
    int N, M;
    cin >> N >> M;

    int org_M = M;
    int digit = 10;
    for (int i = 0; i < 3; i++) {
        int n = M % digit;
        cout << N * n << endl;
        M /= 10;
    }
    cout << N * org_M << endl;

    return 0;
}