import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());

        // 대기 줄
        ArrayDeque<Integer> line = new ArrayDeque<>();

        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            line.add(Integer.parseInt(st.nextToken()));
        }

        if (canGetSnacks(line, n)) {
            System.out.println("Nice");
        } else {
            System.out.println("Sad");
        }
    }

    public static boolean canGetSnacks(ArrayDeque<Integer> line, int n) {
        // 임시 열
        Deque<Integer> stack = new ArrayDeque<>();

        int snack = 1;

        while (snack <= n) {
            // 임시 열에서 꺼낼 수 있으면 먼저 꺼내자
            while (!stack.isEmpty() && stack.peek() == snack) {
                stack.pop();
                snack++;
            }
            
            if (!line.isEmpty()) {
                int firstPerson = line.pollFirst();
                if (snack == firstPerson) {
                    snack++;
                } else {
                    stack.push(firstPerson);
                }
            } else {
                break;
            }
        }
        return snack == n + 1;
    }
}