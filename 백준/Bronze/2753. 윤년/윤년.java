import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int year = Integer.parseInt(st.nextToken());

        if(year%4== 0 && year%100!=0 || year%400==0){
            System.out.println(1);
        }else {
            System.out.println(0);
        }
    }
}