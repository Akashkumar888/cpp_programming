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

			int ans = 0;

			for(int i = 0; i < N; i++)
			{
				int w = sc.nextInt();
				ans = Math.max(ans, w + i);
			}

			System.out.println(ans);
		}

		sc.close();
	}
}
