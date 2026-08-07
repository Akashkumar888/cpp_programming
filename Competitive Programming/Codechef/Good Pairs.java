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

			HashMap<Integer, Integer> freq = new HashMap<>();

			for(int i = 0; i < N; i++)
			{
				int x = sc.nextInt();
				freq.put(x, freq.getOrDefault(x, 0) + 1);
			}

			long ans = 0;

			for(int f : freq.values())
			{
				ans += 1L * f * (f - 1) / 2;
			}

			System.out.println(ans);
		}

		sc.close();
	}
}
