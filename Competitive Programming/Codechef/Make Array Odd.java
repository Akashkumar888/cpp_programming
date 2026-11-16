
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

            int even = 0;
            int odd = 0;

            for (int i = 0; i < N; i++) {
                int a = sc.nextInt();

                if (a % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }

            if (even == 0) {
                System.out.println(0);
            } 
            else if (X % 2 == 1) {
                System.out.println((even + 1) / 2);
            } 
            else if (odd == 0) {
                System.out.println(-1);
            } 
            else {
                System.out.println(even);
            }
        }

        sc.close();
    }
}
