
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            String S = sc.next();

            boolean found = false;

            for (int i = 0; i < N - 1; i++) {
                if (S.charAt(i) == S.charAt(i + 1)) {
                    found = true;
                    break;
                }
            }

            System.out.println(found ? "YES" : "NO");
        }

        sc.close();
    }
}
