
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            int X = sc.nextInt();

            for (int i = 1; i <= N / 2; i++) {
                System.out.print((X - i) + " " + (X + i) + " ");
            }

            if (N % 2 == 1) {
                System.out.print(X);
            }

            System.out.println();
        }

        sc.close();
    }
}
