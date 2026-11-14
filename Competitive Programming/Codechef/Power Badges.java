
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            int n = sc.nextInt();

            int[] a = new int[n];
            int[] freq = new int[101];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                freq[a[i]]++;
            }

            // Calculate prefix frequency
            for (int i = 1; i <= 100; i++) {
                freq[i] += freq[i - 1];
            }

            int ans = 0;

            for (int i = 0; i < n; i++) {
                int lessEqual = freq[a[i]];

                if (2 * lessEqual > n) {
                    ans++;
                }
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
