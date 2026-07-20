import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    static final long MOD = 1000000007;

    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            int N = sc.nextInt();
            String s = sc.next();

            long ans = 1;

            for(int i = 0; i < N; i++)
            {
                char ch = s.charAt(i);

                if(ch == 'c' || ch == 'g' || ch == 'l' || ch == 'r')
                {
                    ans = (ans * 2) % MOD;
                }
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
