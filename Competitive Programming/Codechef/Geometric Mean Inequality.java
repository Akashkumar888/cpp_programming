import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0)
        {
            int N = sc.nextInt();

            int ones = 0;

            for (int i = 0; i < N; i++)
            {
                int x = sc.nextInt();

                if (x == 1)
                {
                    ones++;
                }
            }

            // Four possible repeating valid patterns
            int[][] patterns = {
                {1, 1, -1, -1},
                {1, -1, -1, 1},
                {-1, -1, 1, 1},
                {-1, 1, 1, -1}
            };

            boolean possible = false;

            for (int p = 0; p < 4; p++)
            {
                int countOne = 0;

                for (int i = 0; i < N; i++)
                {
                    if (patterns[p][i % 4] == 1)
                    {
                        countOne++;
                    }
                }

                if (countOne == ones)
                {
                    possible = true;
                    break;
                }
            }

            if (possible)
            {
                System.out.println("Yes");
            }
            else
            {
                System.out.println("No");
            }
        }

        sc.close();
    }
}
