//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

/*
    < Algorithm >
    1. n을 입력받고 이어서 1~n까지의 수열을 입력받는다.
    2. 수열을 array에 저장,
    3. loop 돌며 스택의 top이 가리키는 값과 array에 저장된 값을 비교한다
        -> top < array[index] : push 해야 함
        -> top > array[index] : top보다 작은 값을 스택에서 꺼낼 수 없음 -> "NO" 출력
        -> top == array[index] : pop 해야 함
    4. loop 종료 후 op의 결과 출력

    *** 
    
    배열은 총 3개
    - stack : 스택
    - array : 수열 저장
    - op    : 연산결과 +,- 저장
*/

int main() {
    int stack[SIZE];        // 스택
    int top = -1;           // top 초기화
    char op[SIZE * 2];      // 연산자 담는 배열(결과)

    int n;

    int push_value = 1;
    int index = 0, result_index = 0;

    scanf("%d", &n);
    
    int* array = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]); 
    }

    while (1) {
        if (top == -1 || stack[top] < array[index]) { // push
            top++;
            stack[top] = push_value++;

            op[result_index] = '+';
            result_index++;
        }
        else if (stack[top] == array[index]) {
            top--;
            op[result_index] = '-';
            result_index++;

            index++;
        }
        else {
            printf("NO\n");
            return 0;
        }
        if (result_index == n * 2) {
            break;
        }
    }

    for (int i = 0; i < result_index; i++) {
        printf("%c\n", op[i]);  
    }

    free(array);

    return 0;
}
