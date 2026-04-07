#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
**pseudo code**

숫자 개수, 질문 개수 입력받기
S[N] 선언
for(인덱스 1부터 숫자 개수만큼 반복) {
  S[i] = S[i - 1] + 입력받은 수
}

// 계산하기
for(질문 개수만큼 반복) {
  start, end 입력받기

  cout << S[end] - S[start - 1] << "\n";
}

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;

	int S[100001] = {};

	for (int i = 1; i <= N; i++) {
		int number;
		cin >> number;

		S[i] = S[i - 1] + number;
	}

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;

		cout << S[end] - S[start - 1] << "\n";
	}

    return 0;
}
	