
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            int n = sc.nextInt();

            boolean[] rowZero = new boolean[n];
            boolean[] colZero = new boolean[n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int val = sc.nextInt();

                    if (val == 0) {
                        rowZero[i] = true;
                        colZero[j] = true;
                    }
                }
            }

            boolean possible = true;

            for (int i = 0; i < n; i++) {
                if (!rowZero[i] || !colZero[i]) {
                    possible = false;
                    break;
                }
            }

            System.out.println(possible ? "YES" : "NO");
        }

        sc.close();
    }
}
