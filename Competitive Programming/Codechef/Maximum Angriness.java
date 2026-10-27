import java.io.*;
import java.util.*;

class Codechef {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long N = Long.parseLong(st.nextToken());
            long K = Long.parseLong(st.nextToken());

            long maxInv = N * (N - 1) / 2;
            long swapsNeeded = N / 2;

            if (K >= swapsNeeded) {
                System.out.println(maxInv);
            } else {
                // Maximum inversions with K swaps
                System.out.println(K * (2 * N - 2 * K - 1));
            }
        }
    }
}
