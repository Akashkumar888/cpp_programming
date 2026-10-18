
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder out = new StringBuilder();

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            long[] A = new long[N];
            long[] B = new long[N];

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                A[i] = Long.parseLong(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                B[i] = Long.parseLong(st.nextToken());
            }

            long[] freq = new long[M];

            for (int i = 0; i < N; i++) {
                freq[(int)(A[i] % M)]++;
            }

            long ans = 0;

            for (int i = 0; i < N; i++) {
                int rem = (int)(B[i] % M);
                int need = (M - rem) % M;

                ans += freq[need];
            }

            out.append(ans).append('\n');
        }

        System.out.print(out);
    }
}
