
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder out = new StringBuilder();

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine().trim());

            long[] A = new long[N];
            StringTokenizer st = new StringTokenizer("");

            int idx = 0;
            while (idx < N) {
                while (!st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
                A[idx++] = Long.parseLong(st.nextToken());
            }

            long ans = Math.abs(A[0]);
            for (int i = 1; i < N; i++) {
                ans += Math.abs(A[i] + A[i - 1]);
            }
            ans += Math.abs(A[N - 1]);

            out.append(ans / 2).append('\n');
        }

        System.out.print(out);
    }
}
