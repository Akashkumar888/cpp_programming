
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            long n = sc.nextLong();

            if (n % 2 == 1) {
                System.out.println((n + 1) / 2);
            } else {
                System.out.println(n / 2 + (n + 3) / 4);
            }
        }

        sc.close();
    }
}
