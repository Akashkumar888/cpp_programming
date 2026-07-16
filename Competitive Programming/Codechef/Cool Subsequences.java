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

			HashMap<Integer, Integer> map = new HashMap<>();

			int ans = -1;

			for(int i = 0; i < N; i++)
			{
				int x = sc.nextInt();

				map.put(x, map.getOrDefault(x, 0) + 1);

				if(map.get(x) >= 2 && ans == -1)
				{
					ans = x;
				}
			}

			if(ans == -1)
			{
				System.out.println(-1);
			}
			else
			{
				System.out.println(1);
				System.out.println(ans);
			}
		}

		sc.close();
	}
}
