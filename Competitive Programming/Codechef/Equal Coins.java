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
            long X = sc.nextLong();
            long Y = sc.nextLong();

            long sum = X + 2 * Y;

            if((sum & 1) == 1)
            {
                System.out.println("NO");
            }
            else if(Y % 2 == 0)
            {
                System.out.println("YES");
            }
            else
            {
                if(X >= 2)
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
        }

        sc.close();
    }
}
