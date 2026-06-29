import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0){

            int N = sc.nextInt();

            int[] arr = new int[2 * N];

            for(int i = 0; i < N; i++){
                arr[i] = sc.nextInt();
            }

            for(int i = 0; i < N; i++){
                arr[N + i] = sc.nextInt();
            }

            Arrays.sort(arr);

            long ans = Long.MAX_VALUE;

            for(int i = 0; i + N - 1 < 2 * N; i++){
                ans = Math.min(ans, (long)arr[i + N - 1] - arr[i]);
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
