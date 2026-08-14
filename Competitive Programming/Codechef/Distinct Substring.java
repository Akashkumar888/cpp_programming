import java.util.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            long N = sc.nextLong();
            long K = sc.nextLong();

            // Minimum number of zeros needed for K
            // distinct positive island lengths:
            //
            // 1 + 2 + 3 + ... + K
            long zeros = K * (K + 1) / 2;

            // Need K - 1 ones to separate K islands.
            long minimumLength = zeros + (K - 1);

            if (N >= minimumLength) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

        sc.close();
    }
}
