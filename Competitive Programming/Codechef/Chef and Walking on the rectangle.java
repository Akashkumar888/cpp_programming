
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int K = sc.nextInt();

            int ans;

            if ((N == 1 && M <= 2) ||
                (M == 1 && N <= 2)) {
                ans = 0;
            }
            else if (N == 1 || M == 1) {
                ans = K;
            }
            else {
                ans = (K + 1) / 2;
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
