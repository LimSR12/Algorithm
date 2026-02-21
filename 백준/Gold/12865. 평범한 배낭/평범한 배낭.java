import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static class Node {
        int w;
        int v;

        Node(int w, int v) {
            this.w = w;
            this.v = v;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Node[] list = new Node[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            list[i] = new Node(w, v);
        }

        int[] dp = new int[k + 1];
        for (Node item : list) {
            for (int j = k; j >= item.w; j--) {
                dp[j] = Math.max(
                        dp[j],
                        dp[j - item.w] + item.v
                );
            }
        }

        System.out.println(dp[k]);
    }
}