
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
            int[] A = new int[N];
            int[] freq = new int[N + 1];

            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++) {
                A[i] = Integer.parseInt(st.nextToken());
                freq[A[i]]++;
            }

            int missing = 0;

            for (int K = 0; K <= N; K++) {
                if (K > 0 && freq[K - 1] == 0) {
                    missing++;
                }

                int ans = Math.max(missing, freq[K]);

                if (K > 0) {
                    out.append(' ');
                }
                out.append(ans);
            }

            out.append('\n');
        }

        System.out.print(out);
    }
}
