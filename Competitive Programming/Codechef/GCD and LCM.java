import java.util.*;
import java.io.*;

class Codechef {

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            long X = sc.nextLong();
            long Y = sc.nextLong();
            long K = sc.nextLong();

            long g = gcd(X, Y);

            if (K == 1) {
                System.out.println(Math.min(X, Y) + g);
            } else {
                System.out.println(2 * g);
            }
        }

        sc.close();
    }
}
