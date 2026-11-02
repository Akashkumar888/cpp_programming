
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {

            int n = sc.nextInt();

            if (n == 2) {
                System.out.println(-1);
                continue;
            }

            if (n % 2 == 1) {

                // Odd N: Print increasing permutation
                for (int i = 1; i <= n; i++) {
                    System.out.print(i + " ");
                }

            } else {

                // Even N: Special construction
                for (int i = 1; i <= n - 3; i++) {
                    System.out.print(i + " ");
                }

                System.out.print(n + " ");
                System.out.print((n - 2) + " ");
                System.out.print((n - 1));
            }

            System.out.println();
        }

        sc.close();
    }
}
