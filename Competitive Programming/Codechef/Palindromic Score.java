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
            int X = sc.nextInt();
            int Y = sc.nextInt();
            int Z = sc.nextInt();

            // Bob deletes C
            int ans1 = X + Y - (X % 2) * (Y % 2);

            // Bob deletes B
            int ans2 = X + Z - (X % 2) * (Z % 2);

            // Bob deletes A
            int ans3 = Y + Z - (Y % 2) * (Z % 2);

            // Bob chooses the minimum
            int ans = Math.min(ans1, Math.min(ans2, ans3));

            System.out.println(ans);
        }
    }
}
