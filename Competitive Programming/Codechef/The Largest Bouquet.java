
import java.util.*;

class Codechef {
    static long largestOdd(long x) {
        if (x == 0) return 0;
        return (x % 2 == 1) ? x : x - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            long[][] a = new long[3][3];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    a[i][j] = sc.nextLong();
                }
            }

            long ans = 0;

            // Same tree type
            for (int i = 0; i < 3; i++) {
                long sum = a[i][0] + a[i][1] + a[i][2];
                ans = Math.max(ans, largestOdd(sum));
            }

            // Same color
            for (int j = 0; j < 3; j++) {
                long sum = a[0][j] + a[1][j] + a[2][j];
                ans = Math.max(ans, largestOdd(sum));
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
