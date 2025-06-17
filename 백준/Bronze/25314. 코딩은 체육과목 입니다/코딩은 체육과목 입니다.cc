#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	int count = N / 4;
	if (N % 4 != 0) count++;

	for (int i = 0; i < count; i++) {
		cout << "long ";
	}
	cout << "int";

	return 0;
}