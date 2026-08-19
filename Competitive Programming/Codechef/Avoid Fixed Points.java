import java.util.*;

class Codechef {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            long[] A = new long[N];

            for (int i = 0; i < N; i++) {
                A[i] = sc.nextLong();
            }

            int operations = 0;

            for (int i = 0; i < N; i++) {

                // Original index is i + 1
                // After 'operations' insertions,
                // current position becomes i + 1 + operations.
                int currentPosition = i + 1 + operations;

                if (A[i] == currentPosition) {
                    operations++;
                }
            }

            System.out.println(operations);
        }

        sc.close();
    }
}
