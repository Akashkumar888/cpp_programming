import java.util.*;

class Codechef {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            long[] A = new long[N];
            int[] ans = new int[N];

            for (int i = 0; i < N; i++) {
                A[i] = sc.nextLong();
            }

            // Last element always forms a subarray of length 1
            ans[N - 1] = 1;

            // Calculate from right to left
            for (int i = N - 2; i >= 0; i--) {

                // Different signs
                if ((A[i] > 0) != (A[i + 1] > 0)) {
                    ans[i] = 1 + ans[i + 1];
                } else {
                    ans[i] = 1;
                }
            }

            for (int i = 0; i < N; i++) {
                System.out.print(ans[i]);

                if (i + 1 < N) {
                    System.out.print(" ");
                }
            }

            System.out.println();
        }

        sc.close();
    }
}
