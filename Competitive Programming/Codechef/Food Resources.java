import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    static boolean possible(int[] arr, int m, int days)
    {
        long people = 0;

        for(int food : arr)
        {
            people += food / days;

            if(people >= m) return true;
        }

        return false;
    }

    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] arr = new int[n];

        int high = 0;

        for(int i = 0; i < n; i++)
        {
            arr[i] = sc.nextInt();
            high = Math.max(high, arr[i]);
        }

        int low = 1;
        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(possible(arr, m, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        System.out.println(ans);

        sc.close();
    }
}
