import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    static final long MOD = 1000000007;

    // Binary Exponentiation
    static long power(long base, long exp)
    {
        long ans = 1;

        while(exp > 0)
        {
            if(exp % 2 == 1)
            {
                ans = (ans * base) % MOD;
            }

            base = (base * base) % MOD;
            exp = exp / 2;
        }

        return ans;
    }

    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            int N = sc.nextInt();

            long ans = power(2, N-1);

            System.out.println(ans);
        }
    }
}
