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

            int even = 0;
            int odd = N;

            // The only even-digit palindromic prime is 11.
            // 11 is the 5th palindromic prime.

            if (N >= 5)
            {
                even = 1;
                odd = N - 1;
            }

            System.out.println(even + " " + odd);
        }

        sc.close();
    }
}
