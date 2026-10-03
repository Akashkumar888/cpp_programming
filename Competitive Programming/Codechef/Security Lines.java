import java.util.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            int[] A = new int[N];

            for (int i = 0; i < N; i++) {
                A[i] = sc.nextInt();
            }

            // Stay in queue 1
            int ans = A[0];

            // Try every other queue
            for (int i = 1; i < N; i++) {

                // Distance from queue 1
                int distance = i;

                // Existing people must leave first
                int waiting = A[i] + 1;

                int time = Math.max(distance, waiting);

                ans = Math.min(ans, time);
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
