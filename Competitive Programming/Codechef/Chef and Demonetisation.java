import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            long S = sc.nextLong();
            long N = sc.nextLong();

            long q = S / N;
            long rem = S % N;

            long ans;

            if(rem == 0)
            {
                // S can be completely paid using N-valued coins
                ans = q;
            }
            else if(rem == 1)
            {
                // Remainder 1 can be paid using one 1-coin
                ans = q + 1;
            }
            else if(rem % 2 == 0)
            {
                // Remainder is even and <= N
                // One even coin can pay it
                ans = q + 1;
            }
            else
            {
                // Remainder is odd and greater than 1
                // Use one 1-coin and one even coin
                ans = q + 2;
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
