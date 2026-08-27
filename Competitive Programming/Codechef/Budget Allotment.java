import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            int N = sc.nextInt();
            int X = sc.nextInt();

            ArrayList<Integer> need = new ArrayList<>();

            long surplus = 0;
            int count = 0;

            for(int i = 0; i < N; i++)
            {
                int A = sc.nextInt();

                // Sector already meets minimum requirement
                if(A >= X)
                {
                    count++;

                    // Extra money can be transferred
                    surplus += (A - X);
                }
                else
                {
                    // Money needed to reach X
                    need.add(X - A);
                }
            }

            // Satisfy sectors requiring minimum money first
            Collections.sort(need);

            for(int money : need)
            {
                if(surplus >= money)
                {
                    surplus -= money;
                    count++;
                }
                else
                {
                    break;
                }
            }

            System.out.println(count);
        }
    }
}
