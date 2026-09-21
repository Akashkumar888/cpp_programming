import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            int N = sc.nextInt();
            int M = sc.nextInt();

            int[] freq = new int[M];

            long sum = 0;

            for(int i = 0; i < N; i++)
            {
                int x = sc.nextInt();

                freq[x]++;
                sum += x;
            }

            long ans = sum;


            // Try all possible numbers of operations:
            // 1, 2, ..., M-1

            for(int k = 0; k < M - 1; k++)
            {
                // Which original value will become M-1
                // after k operations?

                int wrapValue = (M - 1 - k + M) % M;

                // Every element normally increases by 1,
                // so sum increases by N.
                //
                // But elements equal to M-1 become 0.
                // Each such element causes a loss of M.

                sum = sum + N - (long)M * freq[wrapValue];

                ans = Math.min(ans, sum);
            }

            System.out.println(ans);
        }
    }
}
