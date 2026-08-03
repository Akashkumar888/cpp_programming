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
            int N = sc.nextInt();

            int[] arr = new int[N];

            for(int i = 0; i < N; i++)
            {
                arr[i] = sc.nextInt();
            }

            int ans = Integer.MAX_VALUE;

            // Try every partition
            for(int mask = 0; mask < (1 << N); mask++)
            {
                int burner1 = 0;
                int burner2 = 0;

                for(int i = 0; i < N; i++)
                {
                    if((mask & (1 << i)) != 0)
                    {
                        burner1 += arr[i];
                    }
                    else
                    {
                        burner2 += arr[i];
                    }
                }

                ans = Math.min(ans, Math.max(burner1, burner2));
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
