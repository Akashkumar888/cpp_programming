import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        boolean[] reported = new boolean[N + 1];

        // Read who each person reports to
        for (int i = 1; i <= N; i++) {

            int r = sc.nextInt();

            if (r != 0) {
                reported[r] = true;
            }
        }

        // Print people whom nobody reports to
        for (int i = 1; i <= N; i++) {

            if (!reported[i]) {
                System.out.print(i + " ");
            }
        }

        sc.close();
    }
}
