
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            int K = sc.nextInt();

            String S = sc.next();

            int mismatch = 0;

            for (int i = 0; i < N / 2; i++) {
                if (S.charAt(i) != S.charAt(N - 1 - i)) {
                    mismatch++;
                }
            }

            int remaining = K - mismatch;

            if (remaining < 0) {
                System.out.println("NO");
            }
            else if (N % 2 == 1 || remaining % 2 == 0) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
        }

        sc.close();
    }
}
