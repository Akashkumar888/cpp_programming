import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        StringBuilder out = new StringBuilder();

        int T = sc.nextInt();

        while (T-- > 0) {
            int n = sc.nextInt();

            long[] a = new long[n];
            long sumA = 0;

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
                sumA += a[i];
            }

            // (N - 1) * S = sum(a[i])
            long S = sumA / (n - 1);

            for (int i = 0; i < n; i++) {
                long x = S - a[i];

                if (i > 0) {
                    out.append(' ');
                }
                out.append(x);
            }

            out.append('\n');
        }

        System.out.print(out);
    }
}
