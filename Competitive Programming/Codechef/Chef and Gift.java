import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0)
        {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int evenCount = 0;
            int oddCount = 0;

            for (int i = 0; i < n; i++)
            {
                int x = sc.nextInt();

                if (x % 2 == 0)
                    evenCount++;
                else
                    oddCount++;
            }

            if (k == 0)
            {
                // Need a non-empty segment containing only odd numbers.
                System.out.println(oddCount > 0 ? "YES" : "NO");
            }
            else
            {
                // Need at least k even numbers in the array.
                System.out.println(evenCount >= k ? "YES" : "NO");
            }
        }

        sc.close();
    }
}
