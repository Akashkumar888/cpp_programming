
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        int T = Integer.parseInt(br.readLine().trim());

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine().trim());

            long sum = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++) {
                sum += Long.parseLong(st.nextToken());
            }

            long k = 0;

            while ((k + 1) * (k + 2) / 2 <= sum) {
                k++;
            }

            System.out.println(k);
        }
    }
}
