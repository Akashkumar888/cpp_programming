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

            int ans = 0;

            // Odd side lengths:
            // 1, 3, 5, ..., N
            // Number of such squares:
            // (N-side+1)^2

            for(int side = 1; side <= N; side += 2)
            {
                int count = N - side + 1;

                ans += count * count;
            }

            System.out.println(ans);
        }
    }
}
