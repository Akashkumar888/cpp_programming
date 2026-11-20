
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    static int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0)
        {
            int n = sc.nextInt();
            int[] a = new int[n];

            for (int i = 0; i < n; i++)
                a[i] = sc.nextInt();

            int g = 0;

            for (int i = 1; i < n; i++)
            {
                g = gcd(g, a[i] - a[i - 1]);
            }

            // Gap from last cut to first cut
            g = gcd(g, 360 - a[n - 1] + a[0]);

            System.out.println(360 / g - n);
        }

        sc.close();
    }
}
