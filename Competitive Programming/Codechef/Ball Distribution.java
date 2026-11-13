
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        int T = Integer.parseInt(br.readLine().trim());

        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            long N = Long.parseLong(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());

            long sum = 0;

            for (int i = 0; i < M; i++) {
                sum += Long.parseLong(st.nextToken());
            }

            long ans = Math.max(0L, sum - N * (M - 1));

            sb.append(ans).append('\n');
        }

        System.out.print(sb);
    }
}
