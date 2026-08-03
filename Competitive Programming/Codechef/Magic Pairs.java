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
			int n = sc.nextInt();

			// Read and ignore the array values
			for(int i = 0; i < n; i++)
			{
				sc.nextLong();
			}

			long ans = (long)n * (n - 1) / 2;

			System.out.println(ans);
		}

		sc.close();
	}
}
