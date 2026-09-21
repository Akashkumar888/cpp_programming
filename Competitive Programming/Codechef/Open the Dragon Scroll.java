import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0)
        {
            int N = sc.nextInt();
            int A = sc.nextInt();
            int B = sc.nextInt();

            // Count number of set bits in A and B
            int oneA = Integer.bitCount(A);
            int oneB = Integer.bitCount(B);

            // Maximum number of 1s possible in XOR
            int xorOne = Math.min(
                oneA + oneB,
                2 * N - (oneA + oneB)
            );

            // Put all XOR 1s in the most significant positions
            int ans = 0;

            for (int i = 0; i < xorOne; i++)
            {
                ans = ans * 2 + 1;
            }

            // Shift them to the highest positions
            ans <<= (N - xorOne);

            System.out.println(ans);
        }
    }
}
