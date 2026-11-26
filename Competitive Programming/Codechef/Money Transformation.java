
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            long mx = 100L * a + b;
            int ans = 0, cnt = 0;

            HashSet<String> set = new HashSet<>();

            while (true) {
                String key = a + "," + b;

                if (set.contains(key)) break;
                set.add(key);

                if (b < c) {
                    if (a == 0) break;

                    a--;
                    b += 100;
                }

                b -= c;

                int temp = a;
                a = b;
                b = temp;

                cnt++;

                long money = 100L * a + b;

                if (money > mx) {
                    mx = money;
                    ans = cnt;
                }
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
