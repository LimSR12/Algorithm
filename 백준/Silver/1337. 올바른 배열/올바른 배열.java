import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        System.out.println(solve(arr, N));
    }

    static int solve(int[] arr, int N) {
        Arrays.sort(arr);

        int left = 0;
        int maxCount = 1;

        for (int right = 0; right < arr.length; right++) {
            // 윈도우 범위를 벗어나면 left를 당김
            while (arr[right] - arr[left] >= 5) {
                left++;
            }
            maxCount = Math.max(maxCount, right - left + 1);
        }

        return 5 - maxCount;
    }
}
