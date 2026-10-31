
import java.util.*;
import java.io.*;

class Codechef {
    static final long MOD = 1000000007L;
    static final int MAX = 1000000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        long[] fact = new long[MAX + 1];

        // Precompute factorials
        fact[0] = 1;

        for (int i = 1; i <= MAX; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        int T = Integer.parseInt(br.readLine().trim());

        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine().trim());

            StringTokenizer st = new StringTokenizer(br.readLine());

            long ans = 0;

            for (int i = 0; i < N; i++) {
                int x = Integer.parseInt(st.nextToken());

                ans = (ans + fact[x]) % MOD;
            }

            sb.append(ans).append('\n');
        }

        System.out.print(sb);
    }
}
