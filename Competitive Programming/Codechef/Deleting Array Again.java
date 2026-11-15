
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            int[] A = new int[N];
            int[] C = new int[N];

            for (int i = 0; i < N; i++) {
                A[i] = sc.nextInt();
            }

            for (int i = 0; i < N; i++) {
                C[i] = sc.nextInt();
            }

            long ans = 0;
            int minCost = Integer.MAX_VALUE;

            for (int i = 0; i < N; i++) {

                minCost = Math.min(minCost, C[i]);

                ans += (long) A[i] * minCost;
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
