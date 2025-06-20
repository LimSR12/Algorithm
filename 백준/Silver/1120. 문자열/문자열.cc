#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main() {
    
    string A, B; // A <= B

    cin >> A >> B;

    int min_diff = INT_MAX;
    int lenA = A.length();
    int lenB = B.length();

    // min_diff 를 찾는 그 시점에서 A의 앞뒤로 B랑 같은 문자 붙여주면 됨
    // A를 슬라이드하면서 B에 대보며 min_diff 를 찾자!
    for (int i = 0; i <= lenB - lenA; i++) {
        int diff = 0;
        for (int j = 0; j < lenA; j++) {
            if (A[j] != B[i + j]) {
                diff++;
            }
        }
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << '\n';

    return 0;
}