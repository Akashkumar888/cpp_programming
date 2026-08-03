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

            HashMap<Integer, Integer> freq = new HashMap<>();

            // Frequency of each number
            for(int i = 0; i < N; i++)
            {
                int x = sc.nextInt();
                freq.put(x, freq.getOrDefault(x, 0) + 1);
            }

            HashMap<Integer, Integer> cnt = new HashMap<>();

            // Frequency of frequencies
            for(int f : freq.values())
            {
                cnt.put(f, cnt.getOrDefault(f, 0) + 1);
            }

            int ans = Integer.MAX_VALUE;
            int mx = 0;

            for(Map.Entry<Integer, Integer> entry : cnt.entrySet())
            {
                int frequency = entry.getKey();
                int occurrences = entry.getValue();

                if(occurrences > mx)
                {
                    mx = occurrences;
                    ans = frequency;
                }
                else if(occurrences == mx)
                {
                    ans = Math.min(ans, frequency);
                }
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
