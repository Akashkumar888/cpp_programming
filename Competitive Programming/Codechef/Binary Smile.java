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

            String A = sc.next();
            String B = sc.next();

            ArrayList<Integer> posA = new ArrayList<>();
            ArrayList<Integer> posB = new ArrayList<>();

            // Store positions of 1 in A
            for(int i = 0; i < N; i++)
            {
                if(A.charAt(i) == '1')
                {
                    posA.add(i);
                }
            }

            // Store positions of 1 in B
            for(int i = 0; i < N; i++)
            {
                if(B.charAt(i) == '1')
                {
                    posB.add(i);
                }
            }

            // Number of 1s must be same
            if(posA.size() != posB.size())
            {
                System.out.println(-1);
                continue;
            }

            int operations = 0;

            for(int i = 0; i < posA.size(); i++)
            {
                if(!posA.get(i).equals(posB.get(i)))
                {
                    operations++;
                }
            }

            System.out.println(operations);
        }
    }
}
