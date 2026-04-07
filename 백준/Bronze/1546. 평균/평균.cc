#include <iostream>
#include <algorithm>
#include <vector>

/*
N 입력받기
길이 N의 배열 선언하기 (scores)

for(scores 길이만큼 반복) {
  scores[i] 에 성적 저장하기
}

// 최대값 찾으면서 전체 합 구하기
max, sum, avg 변수 선언하기
for(scores 길이만큼 반복) {
  max 보다 크면 저장, 아니면 넘어감
  sum += scores[i];
}

avg = sum / max * 100 / 3;
*/

using namespace std;

int main() {
	
	int N;
	cin >> N;
	int scores[1000];

	for (int i = 0; i < N; i++) {
		cin >> scores[i];
	}
	
	long max = 0;
	long sum = 0;
	double avg = 0;

	for (int i = 0; i < N; i++) {
		if(max < scores[i]) {
			max = scores[i];
		}
		sum += scores[i];
	}	

	avg = sum * 100.0 / max / N;
	cout << avg;

    return 0;
}
	