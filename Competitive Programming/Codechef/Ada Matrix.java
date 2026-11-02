
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int n = sc.nextInt();

            int[][] a = new int[n][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = sc.nextInt();
                }
            }

            // s[j] represents whether column j
            // is effectively transposed.
            int[] s = new int[n + 2];

            for (int j = 2; j <= n; j++) {

                int normal = j;
                int swapped = (j - 1) * n + 1;

                if (a[0][j - 1] == normal) {
                    s[j] = 0;
                } else if (a[0][j - 1] == swapped) {
                    s[j] = 1;
                }
            }

            // s[n + 1] = 0 by default.
            int ans = 0;

            for (int j = 2; j <= n; j++) {
                ans += (s[j] ^ s[j + 1]);
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
