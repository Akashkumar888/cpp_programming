
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            long[] A = new long[N];
            long totalSum = 0;

            for (int i = 0; i < N; i++) {
                A[i] = sc.nextLong();
                totalSum += A[i];
            }

            long prefixSum = 0;
            long ans = totalSum;

            // Try every possible prefix length, including zero
            for (int i = 0; i < N; i++) {
                prefixSum += A[i];

                long time = Math.max(prefixSum, totalSum - prefixSum);
                ans = Math.min(ans, time);
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
