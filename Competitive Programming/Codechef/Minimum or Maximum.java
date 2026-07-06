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

            int[] B = new int[N];

            for(int i = 0; i < N; i++)
                B[i] = sc.nextInt();

            int mn = B[0];
            int mx = B[0];

            boolean ok = true;

            for(int i = 1; i < N; i++)
            {
                if(B[i] > mx)
                {
                    mx = B[i];
                }
                else if(B[i] < mn)
                {
                    mn = B[i];
                }
                else if(B[i] == mn || B[i] == mx)
                {
                    // possible, range unchanged
                }
                else
                {
                    ok = false;
                    break;
                }
            }

            if(ok)
                System.out.println("YES");
            else
                System.out.println("NO");
        }

        sc.close();
    }
}
