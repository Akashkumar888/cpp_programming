
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            int n = s.length();

            char first = s.charAt(0);
            char last = s.charAt(n - 1);

            int ans = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                char ch = s.charAt(i);

                if (ch != first && ch != last) {
                    cnt++;
                    ans = Math.max(ans, cnt);
                } else {
                    cnt = 0;
                }
            }

            System.out.println(ans == 0 ? -1 : ans);
        }

        sc.close();
    }
}
