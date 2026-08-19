import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    static int hits(int S, int a, int b, int c)
    {
        if(a + b + c <= S)
            return 1;

        if(a + b <= S)
            return 2;

        if(b + c <= S)
            return 2;

        return 3;
    }

    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            int S = sc.nextInt();
            int W1 = sc.nextInt();
            int W2 = sc.nextInt();
            int W3 = sc.nextInt();

            int ans = Math.min(
                hits(S, W1, W2, W3),
                hits(S, W3, W2, W1)
            );

            System.out.println(ans);
        }

        sc.close();
    }
}
