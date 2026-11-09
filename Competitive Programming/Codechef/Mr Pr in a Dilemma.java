
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long c = sc.nextLong();
            long d = sc.nextLong();

            long diff = Math.abs(a - b);
            long moveDiff = Math.abs(c - d);

            if (moveDiff == 0) {
                System.out.println(diff == 0 ? "YES" : "NO");
            } else {
                System.out.println(diff % moveDiff == 0 ? "YES" : "NO");
            }
        }

        sc.close();
    }
}
