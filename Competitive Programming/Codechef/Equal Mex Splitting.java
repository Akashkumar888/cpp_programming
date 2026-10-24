
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        int T = Integer.parseInt(br.readLine().trim());

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine().trim());
            StringTokenizer st = new StringTokenizer(br.readLine());

            int zeros = 0;

            for (int i = 0; i < N; i++) {
                int x = Integer.parseInt(st.nextToken());
                if (x == 0) {
                    zeros++;
                }
            }

            System.out.println(Math.max(zeros, N - zeros));
        }
    }
}
