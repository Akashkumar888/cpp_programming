import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int X = sc.nextInt();
            int Y = sc.nextInt();
            int K = sc.nextInt();
            int N = sc.nextInt();

            // Pages still required
            int requiredPages = X - Y;

            boolean possible = false;

            for (int i = 0; i < N; i++) {

                int P = sc.nextInt();
                int C = sc.nextInt();

                // Check pages and price
                if (P >= requiredPages && C <= K) {
                    possible = true;
                }
            }

            if (possible) {
                System.out.println("LuckyChef");
            }
            else {
                System.out.println("UnluckyChef");
            }
        }

        sc.close();
    }
}
