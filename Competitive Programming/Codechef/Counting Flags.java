
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            long n = sc.nextLong();

            long p1 = n * (n - 1) * (n - 1);

            long p2 = n * (n - 1) * (n - 2);

            long p3 = n * (n - 1) * (n - 2) * (n - 2);

            long ans = 2 * p1 + p2 + 2 * p3;

            System.out.println(ans);
        }

        sc.close();
    }
}
