import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            int minValue = Integer.MAX_VALUE;
            int answer = 1;

            for (int i = 1; i <= N; i++) {

                int x = sc.nextInt();

                // Keep the first occurrence of minimum
                if (x < minValue) {
                    minValue = x;
                    answer = i;
                }
            }

            System.out.println(answer);
        }

        sc.close();
    }
}
