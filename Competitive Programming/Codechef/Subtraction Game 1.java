import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    // Find GCD of two numbers
    static long gcd(long a, long b)
    {
        while(b != 0)
        {
            long temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            int N = sc.nextInt();

            // Start with first element
            long ans = sc.nextLong();

            // GCD with all remaining elements
            for(int i = 1; i < N; i++)
            {
                long num = sc.nextLong();
                ans = gcd(ans, num);
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
