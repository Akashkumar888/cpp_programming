import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int Q = sc.nextInt();

        while(Q-- > 0)
        {
            int N = sc.nextInt();

            String S = sc.next();
            String T = sc.next();
            String U = sc.next();

            // Find rotation value
            int k = (T.charAt(0) - S.charAt(0) + 26) % 26;

            StringBuilder ans = new StringBuilder();

            for(int i = 0; i < N; i++)
            {
                char ch = U.charAt(i);

                char newChar = (char)('a' + (ch - 'a' + k) % 26);

                ans.append(newChar);
            }

            System.out.println(ans.toString());
        }

        sc.close();
    }
}
