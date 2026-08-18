import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0)
        {
            int N = sc.nextInt();
            String S = sc.next();

            int count = 0;

            // Count number of set bits
            for (int i = 0; i < N; i++)
            {
                if (S.charAt(i) == '1')
                {
                    count++;
                }
            }

            // More than 3 powers are already required
            if (count > 3)
            {
                System.out.println("NO");
            }

            // Already exactly 3 powers
            else if (count == 3)
            {
                System.out.println("YES");
            }

            // Two powers can be converted into exactly
            // three powers by splitting one power.
            else if (count == 2)
            {
                System.out.println("YES");
            }

            // Only one power of 2
            else
            {
                // The single 1 must represent 2^k.
                //
                // k = 0 -> 1  -> cannot split
                // k = 1 -> 2  -> 1 + 1 (only 2 terms)
                // k >= 2 -> can make exactly 3 terms
                //
                // Position from right = N - 1 - i

                int pos = -1;

                for (int i = 0; i < N; i++)
                {
                    if (S.charAt(i) == '1')
                    {
                        pos = N - 1 - i;
                        break;
                    }
                }

                if (pos >= 2)
                {
                    System.out.println("YES");
                }
                else
                {
                    System.out.println("NO");
                }
            }
        }

        sc.close();
    }
}
