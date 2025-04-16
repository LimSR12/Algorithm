#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

void findBomb(char** arr, int N, int M) {
	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '*') {
				printf("%c", arr[i][j]);
				continue;
			}
			else { // look around
				for (int y = i - 1; y <= i + 1; y++) {
					if (y < 0 || y >= N) continue;
					for (int x = j - 1; x <= j + 1; x++) {
						if (x < 0 || x >= M) continue;
						else if(arr[y][x] == '*') {
							count++;
						}
					}
				}
				printf("%d", count);
				count = 0;
			}
		}
		printf("\n");
	}
}



int main() {
	while (1) {
		int N;
		int M;
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) {
			break;
		}
		char** arr;

		arr = (char**)malloc(sizeof(char*) * N);
		for (int i = 0; i < N; i++) {
			arr[i] = (char*)malloc(sizeof(char) * M);
		}

		for (int i = 0; i < N; i++) {
			getchar();
			for (int j = 0; j < M; j++) {
				scanf("%c", &arr[i][j]);
			}
		}

		findBomb(arr, N, M);



		for (int i = 0; i < N; i++) {
			free(arr[i]);
		}
		free(arr);
	}
	
}
