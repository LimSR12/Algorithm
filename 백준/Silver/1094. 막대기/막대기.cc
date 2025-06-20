#include <iostream>

using namespace std;

int main() {
    
    int X;
    cin >> X;

    int answer = 0;
    while (X > 0) {
        if (X % 2 == 1) {
            answer++;
        }
        X /= 2;
    }

    cout << answer;

    return 0;
}