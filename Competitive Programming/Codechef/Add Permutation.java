import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();
            int K = sc.nextInt();

            int[] P = new int[N];

            // Initially identity permutation
            for (int i = 0; i < N; i++) {
                P[i] = i + 1;
            }

            // Reverse first N-K+1 elements
            int l = 0;
            int r = N - K;

            while (l < r) {
                int temp = P[l];
                P[l] = P[r];
                P[r] = temp;

                l++;
                r--;
            }

            // Print permutation
            for (int i = 0; i < N; i++) {
                System.out.print(P[i] + " ");
            }

            System.out.println();
        }

        sc.close();
    }
}
