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

            // Largest number at position 1
            System.out.print(N + " ");

            // Third largest number at position 2
            System.out.print(N - 2 + " ");

            // Put remaining numbers in the middle
            for(int i = 1; i <= N - 3; i++)
            {
                System.out.print(i + " ");
            }

            // Second largest number at the last position
            System.out.println(N - 1);
        }

        sc.close();
    }
}
