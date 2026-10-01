import java.util.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0)
        {
            int N = sc.nextInt();
            long K = sc.nextLong();

            long min = Long.MAX_VALUE;
            long max = Long.MIN_VALUE;

            for (int i = 0; i < N; i++)
            {
                long x = sc.nextLong();

                min = Math.min(min, x);
                max = Math.max(max, x);
            }

            if (N == 1 || min + max <= K)
                System.out.println("YES");
            else
                System.out.println("NO");
        }

        sc.close();
    }
}
