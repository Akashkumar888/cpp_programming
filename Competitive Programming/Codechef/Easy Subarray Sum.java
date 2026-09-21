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

            int[] arr = new int[N];

            for (int i = 0; i < N; i++)
            {
                arr[i] = sc.nextInt();
            }

            // Find first positive element
            int first = -1;

            for (int i = 0; i < N; i++)
            {
                if (arr[i] > 0)
                {
                    first = i;
                    break;
                }
            }

            // If there is no positive element,
            // maximum subarray sum is already 0.
            if (first == -1)
            {
                System.out.println(0);
                continue;
            }

            // Find last positive element
            int last = -1;

            for (int i = N - 1; i >= 0; i--)
            {
                if (arr[i] > 0)
                {
                    last = i;
                    break;
                }
            }

            int count = 0;

            // Count negative elements between
            // first positive and last positive.
            for (int i = first; i <= last; i++)
            {
                if (arr[i] < 0)
                {
                    count++;
                }
            }

            System.out.println(count);
        }

        sc.close();
    }
}
