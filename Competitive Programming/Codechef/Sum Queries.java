
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();
        int M = sc.nextInt();

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < M; i++) {
            long q = sc.nextLong();

            long ans = Math.max(0L, N - Math.abs(q - (2 * N + 1)));

            sb.append(ans).append('\n');
        }

        System.out.print(sb);
        sc.close();
    }
}
