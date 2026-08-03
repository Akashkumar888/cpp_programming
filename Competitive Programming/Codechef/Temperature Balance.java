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

			long prefix = 0;
			long ans = 0;

			for(int i = 0; i < N; i++)
			{
				long x = sc.nextLong();

				prefix += x;

				if(i != N - 1)
				{
					ans += Math.abs(prefix);
				}
			}

			System.out.println(ans);
		}

		sc.close();
	}
}
