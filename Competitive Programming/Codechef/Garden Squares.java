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
			int M = sc.nextInt();

			char[][] grid = new char[N][M];

			for(int i = 0; i < N; i++)
			{
				grid[i] = sc.next().toCharArray();
			}

			long ans = 0;

			for(int i = 0; i < N; i++)
			{
				for(int j = 0; j < M; j++)
				{
					int maxSide = Math.min(N - i - 1, M - j - 1);

					for(int len = 1; len <= maxSide; len++)
					{
						char ch = grid[i][j];

						if(grid[i][j + len] == ch &&
						   grid[i + len][j] == ch &&
						   grid[i + len][j + len] == ch)
						{
							ans++;
						}
					}
				}
			}

			System.out.println(ans);
		}

		sc.close();
	}
}
