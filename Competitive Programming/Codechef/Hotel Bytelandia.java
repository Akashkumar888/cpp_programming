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
            int N = sc.nextInt();

            int[] arrival = new int[N];
            int[] departure = new int[N];

            for(int i=0;i<N;i++)
            {
                arrival[i] = sc.nextInt();
            }

            for(int i=0;i<N;i++)
            {
                departure[i] = sc.nextInt();
            }

            Arrays.sort(arrival);
            Arrays.sort(departure);

            int i = 0;
            int j = 0;

            int current = 0;
            int answer = 0;

            while(i < N && j < N)
            {
                // Arrival is before departure
                if(arrival[i] < departure[j])
                {
                    current++;
                    answer = Math.max(answer, current);
                    i++;
                }
                else
                {
                    // Departure is first when times are equal
                    current--;
                    j++;
                }
            }

            System.out.println(answer);
        }
    }
}
