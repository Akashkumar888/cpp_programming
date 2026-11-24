
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            long N = sc.nextLong();
            long A = sc.nextLong();

            if (N == 1) {
                System.out.println(A % 2 == 0 ? "Even" : "Odd");
            }
            else if (A % 2 == 1) {
                System.out.println(N % 2 == 0 ? "Even" : "Odd");
            }
            else {
                System.out.println("Impossible");
            }
        }

        sc.close();
    }
}
