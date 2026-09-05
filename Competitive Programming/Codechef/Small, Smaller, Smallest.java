import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            int N = sc.nextInt();
            String S = sc.next();

            int count = 0;

            // Count number of 1s
            for(int i = 0; i < N; i++)
            {
                if(S.charAt(i) == '1')
                {
                    count++;
                }
            }

            // No 1s -> nothing can be deleted
            if(count == 0)
            {
                System.out.println(N);
            }

            // Even number of 1s -> all 1s can be deleted
            else if(count % 2 == 0)
            {
                System.out.println(0);
            }

            // Odd number of 1s -> exactly one 1 remains
            else
            {
                System.out.println(1);
            }
        }
    }
}
