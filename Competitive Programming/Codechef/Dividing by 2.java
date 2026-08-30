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

            int[] A = new int[N];

            for(int i = 0; i < N; i++)
            {
                A[i] = sc.nextInt();
            }

            // cost[x] = total operations needed
            // to make all numbers equal to x
            HashMap<Integer, Long> cost = new HashMap<>();

            // Every number can reach 0
            // by repeatedly dividing by 2.
            for(int i = 0; i < N; i++)
            {
                int x = A[i];
                int operations = 0;

                while(x > 0)
                {
                    cost.put(
                        x,
                        cost.getOrDefault(x, 0L) + operations
                    );

                    x /= 2;
                    operations++;
                }

                // x = 0
                cost.put(
                    0,
                    cost.getOrDefault(0, 0L) + operations
                );
            }

            long answer = Long.MAX_VALUE;

            // A value is a possible final value
            // only if every element can reach it.
            for(Map.Entry<Integer, Long> entry : cost.entrySet())
            {
                if(entry.getValue() >= 0)
                {
                    int value = entry.getKey();

                    // Count how many original elements
                    // can reach this value.
                    int count = 0;

                    for(int i = 0; i < N; i++)
                    {
                        int x = A[i];

                        while(x > value)
                        {
                            x /= 2;
                        }

                        if(x == value)
                        {
                            count++;
                        }
                    }

                    if(count == N)
                    {
                        answer = Math.min(answer, entry.getValue());
                    }
                }
            }

            System.out.println(answer);
        }

        sc.close();
    }
}
