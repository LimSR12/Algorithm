import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int h = Integer.parseInt(st.nextToken()); // 0 ≤ H ≤ 23
        int m = Integer.parseInt(st.nextToken()); // 0 ≤ M ≤ 59

        int total = h * 60 + m;
        int day = 24 * 60;
        total = (total - 45 + day) % (day);

        System.out.println((total / 60) + " " + (total % 60));
    }
}