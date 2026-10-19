
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        int T = Integer.parseInt(br.readLine().trim());

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            String S = br.readLine().trim();

            int[] freq = new int[5];

            for (int i = 0; i < N; i++) {
                freq[S.charAt(i) - 'A']++;
            }

            Arrays.sort(freq);

            int remaining = N;
            int ans = Integer.MAX_VALUE;

            // Try learning 0 to 5 languages
            for (int k = 0; k <= 5; k++) {
                int translatorCost = remaining * (remaining + 1) / 2;
                int totalCost = k * C + translatorCost;

                ans = Math.min(ans, totalCost);

                if (k < 5) {
                    remaining -= freq[4 - k];
                }
            }

            System.out.println(ans);
        }
    }
}
