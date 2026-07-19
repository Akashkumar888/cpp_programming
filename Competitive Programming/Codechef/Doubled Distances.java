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

			long[] arr = new long[N];

			for(int i = 0; i < N; i++)
			{
				arr[i] = sc.nextLong();
			}

			Arrays.sort(arr);

			boolean ok = true;

			for(int i = 1; i < N - 1; i++)
			{
				long d1 = arr[i] - arr[i - 1];
				long d2 = arr[i + 1] - arr[i];

				if(!(d1 == 2 * d2 || 2 * d1 == d2))
				{
					ok = false;
					break;
				}
			}

			System.out.println(ok ? "Yes" : "No");
		}

		sc.close();
	}
}
