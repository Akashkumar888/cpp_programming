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
            String A = sc.next();
            String B = sc.next();

            int N = sc.nextInt();

            int[] freq = new int[26];

            // Count characters available in parents
            for(int i = 0; i < A.length(); i++)
            {
                freq[A.charAt(i) - 'a']++;
            }

            for(int i = 0; i < B.length(); i++)
            {
                freq[B.charAt(i) - 'a']++;
            }


            boolean ok = true;

            // Read all children and directly
            // consume their required characters

            for(int i = 0; i < N; i++)
            {
                String C = sc.next();

                for(int j = 0; j < C.length(); j++)
                {
                    int idx = C.charAt(j) - 'a';

                    freq[idx]--;

                    if(freq[idx] < 0)
                    {
                        ok = false;
                    }
                }
            }

            if(ok)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
