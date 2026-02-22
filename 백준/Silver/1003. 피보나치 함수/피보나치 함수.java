import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static Integer[][] dp = new Integer[41][2];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        dp[0][0] = 1;    // N=0 일 때의 0 호출 횟수
        dp[0][1] = 0;    // N=0 일 때의 1 호출 횟수
        dp[1][0] = 0;    // N=1 일 때의 0 호출 횟수
        dp[1][1] = 1;    // N=1 일 때의 1 호출 횟수

        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            fibonacci(n);
            System.out.println(dp[n][0] + " " + dp[n][1]);
        }
    }

    static Integer[] fibonacci(int N) {
        // N에 대한 0, 1의 호출 횟수가 없을 때(탐색하지 않은 값일 때)
        if (dp[N][0] == null || dp[N][1] == null) {
            dp[N][0] = fibonacci(N - 1)[0] + fibonacci(N - 2)[0];
            dp[N][1] = fibonacci(N - 1)[1] + fibonacci(N - 2)[1];
        }
        // N에 대한 0과 1, 즉 [N][0]과 [N][1] 을 담고있는 [N]을 반환한다.
        return dp[N];
    }

    /*
    피보나치 함수 호출 시 0과 1이 출력되는 횟수 규칙
    N이 증가할 때,
    fibonacci(N)을 호출하면
    0과 1이 호출되는 횟수는 다음과 같은 규칙을 따른다.

    +-----+----------------------+----------------------+
    |  N  |  fibonacci(0) 호출수  |  fibonacci(1) 호출수  |
    +-----+----------------------+----------------------+
    |  0  |          1           |          0           |
    |  1  |          0           |          1           |
    |  2  |          1           |          1           |
    |  3  |          1           |          2           |
    |  4  |          2           |          3           |
    |  5  |          3           |          5           |
    |  6  |          5           |          8           |
    |  7  |          8           |         13           |
    |  8  |         13           |         21           |
    +-----+----------------------+----------------------+
    관찰되는 규칙:

    1. N에 대한 0 호출 횟수 = (N-1)의 1 호출 횟수

    2. N에 대한 1 호출 횟수 = (N-1)의 0 호출 횟수 + (N-1)의 1 호출 횟수

    즉, fibonacci(N)의 호출 횟수는 이전 두 단계의 결과를 더하는 피보나치 형태를 따른다.

    반복문으로 표현하면:

    초기값:
    zero = 1   // N = 0일 때 0 호출 횟수
    one  = 0   // N = 0일 때 1 호출 횟수

    이후 N번 반복:

    next_zero = one
    next_one  = zero + one

    이 과정을 반복하면
    fibonacci(N) 호출 시
    0과 1의 호출 횟수를 구할 수 있다.
     */
}