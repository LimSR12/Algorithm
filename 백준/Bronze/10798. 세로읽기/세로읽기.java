import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[][] board = new char[5][15];

        for (int row = 0; row < 5; row++) {
            String line = br.readLine();
            for (int col = 0; col < line.length(); col++) {
                board[row][col] = line.charAt(col);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int col = 0; col < 15; col++) {
            for (int row = 0; row < 5; row++) {
                if (board[row][col] != '\0') {
                    sb.append(board[row][col]);
                }
            }
        }

        System.out.print(sb.toString());
    }
}