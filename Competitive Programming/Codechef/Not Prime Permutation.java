
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();

            int[] p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = sc.nextInt();
            }

            if (n <= 2) {
                System.out.println(-1);
                continue;
            }

            int[] mp = new int[n + 1];

            // Odd numbers
            for (int i = 1; i <= n; i += 2) {
                mp[i] = (i + 2 <= n) ? i + 2 : 1;
            }

            // Even numbers
            for (int i = 2; i <= n; i += 2) {
                mp[i] = (i + 2 <= n) ? i + 2 : 2;
            }

            for (int i = 0; i < n; i++) {
                System.out.print(mp[p[i]] + " ");
            }

            System.out.println();
        }

        sc.close();
    }
}
