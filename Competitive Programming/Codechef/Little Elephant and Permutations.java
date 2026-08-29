import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            int N = sc.nextInt();

            boolean good = true;

            for(int i = 0; i < N; i++)
            {
                int x = sc.nextInt();

                // In a good permutation,
                // every element can be at most
                // one position away from its sorted position.
                if(Math.abs(x - (i + 1)) > 1)
                {
                    good = false;
                }
            }

            if(good)
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }
        }

        sc.close();
    }
}
