#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    
    long long min, max;
    cin >> min >> max;

    long long len = max - min + 1;
    long long sqrt_max = (int)(ceil(sqrt(max)));

    vector<bool> is_prime(sqrt_max + 1, true);      // 소수 벡터
    vector<long long> prime_squares;                // 소수의 제곱수 벡터
    vector<bool> is_square_nono(len, true);         // min~max 사이의 제곱ㄴㄴ수

    // 에라토스테네스의 체
    for (int i = 2; i <= sqrt_max; i++) {
        if (is_prime[i]) {
            int multiple = i + i;
            while (multiple <= sqrt_max) {
                is_prime[multiple] = false;
                multiple += i;
            }
        }
    }

    // 소수 제곱 벡터 만들고
    for (int i = 2; i <= sqrt_max; i++) {
        if (is_prime[i]) {
            prime_squares.push_back((long long)i * (long long)i);
        }
    }
    
    // 제곱수의 배수들 제거
    for (auto& prime_sq : prime_squares) {
        // min 이상에서 시작하는, 어떤 소수 제곱수(prime_sq)의 가장 첫 번째 배수를 구함
        long long square_multiple = (long long)(ceil(((double)min) / ((double)prime_sq))) * prime_sq;

        // 그 첫번째 배수부터 max 까지 제거
        while (square_multiple <= max) {
            is_square_nono[square_multiple - min] = false;
            square_multiple += prime_sq;
        }
    }

    int result = 0;
    for (int i = 0; i < len; i++) {
        if (is_square_nono[i]) result++;
    }

    cout << result << '\n';

    return 0;
}