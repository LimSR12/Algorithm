#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    int N, K;

    cin >> N >> K;

    vector<bool> is_prime(N + 1, true);
    int cnt = 0;

    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i; j <= N; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    cnt++;
                    if (cnt == K) {
                        cout << j << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}