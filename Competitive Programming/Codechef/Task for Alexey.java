
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    
    static long gcd(long a, long b) {
        while(b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while(t-- > 0) {
            int n = sc.nextInt();

            long[] a = new long[n];

            for(int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
            }

            long ans = Long.MAX_VALUE;

            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    ans = Math.min(ans, lcm(a[i], a[j]));
                }
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
