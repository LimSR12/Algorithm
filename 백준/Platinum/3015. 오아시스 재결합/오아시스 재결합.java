import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    static class Node {
        int h;
        int cnt;

        Node(int h, int cnt) {
            this.h = h;
            this.cnt = cnt;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // n 명, 1 <= n <= 500,000

        Deque<Node> stack = new ArrayDeque<>();
        long ans = 0;

        for (int i = 0; i < n; i++) {
            int h = Integer.parseInt(br.readLine());
            int same = 1;

            while (!stack.isEmpty() && stack.peek().h < h) {
                ans += stack.peek().cnt;
                stack.pop();
            }

            if (!stack.isEmpty() && stack.peek().h == h) {
                Node top = stack.pop();
                ans += top.cnt;
                same = top.cnt + 1;

                // 키가 같은 사람 전부 ans 에 더해줬고, 그 이전에 또 사람이 남아있다면 +1
                if (!stack.isEmpty()) ans += 1;
            } else if (!stack.isEmpty()) {
                ans += 1;
            }

            stack.push(new Node(h, same));
        }
        System.out.println(ans);
    }
    /*
      [풀이 흐름]
      1. 나보다 키가 작은 사람이 들어올 때 (While문)
        - 현재 사람 때문에 그 뒤에 오는 사람들은 앞에 있는 작은 사람들을 절대 볼 수 없다.
        - 따라서 스택에서 pop하며 해당 작은 사람의 숫자(cnt)만큼 정답(ans)에 더해준다.
      2. 나와 키가 같은 사람이 들어올 때 (if문)
        - 스택의 top과 키가 같다면, 이들은 서로 볼 수 있다.
        - top.cnt만큼 정답에 더하고, same 변수를 갱신하여 현재 나를 포함한 '같은 키의 인원수'를 누적한다.
        - 만약 이 같은 키 그룹 앞에 누군가 더 있다면(키가 더 큰 사람), 그 사람과도 볼 수 있으므로 +1을 해준다.
      3. 나보다 키가 큰 사람이 들어올 때 (else if문)
        - 스택에 나보다 큰 사람이 남아있다면, 그 사람과 나는 서로 볼 수 있으므로 ans += 1
     */
}