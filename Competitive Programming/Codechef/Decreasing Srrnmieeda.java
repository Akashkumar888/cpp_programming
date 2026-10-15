
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder ans = new StringBuilder();

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long L = Long.parseLong(st.nextToken());
            long R = Long.parseLong(st.nextToken());

            if (R < 2 * L) {
                ans.append(R).append('\n');
            } else {
                ans.append(-1).append('\n');
            }
        }

        System.out.print(ans);
    }
}
