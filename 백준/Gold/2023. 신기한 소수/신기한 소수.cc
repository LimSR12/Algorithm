#include <iostream>

using namespace std;

void dfs(int number, int jarisu);
bool isPrime(int number);
static int N;

int main() {
	cin >> N;

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	return 0;
}

void dfs(int number, int jarisu) {
	// N자릿수 도달했으면 출력하고 리턴
	if (jarisu == N) {
		if (isPrime(number)) {
			cout << number << "\n";
		}
		return;
	}

	// 아니라면 다음 자릿수로 재귀 호출
	// 이때 (number * 10 + 새로운 수) 인데, 새로운 수는 짝수 제외
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 0) continue;
		if (isPrime(number * 10 + i)) {
			dfs(number * 10 + i, jarisu + 1);
		}
	}
}

bool isPrime(int number) {
	for (int i = 2; i <= number / 2; i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}
