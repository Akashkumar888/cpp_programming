
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

			String[] arr = new String[N];

			for(int i = 0; i < N; i++)
			{
				arr[i] = sc.next();
			}

			boolean ok = true;

			for(int i = 0; i < N; i++)
			{
				if(arr[i].equals("cookie"))
				{
					if(i == N - 1 || !arr[i + 1].equals("milk"))
					{
						ok = false;
						break;
					}
				}
			}

			if(ok)
				System.out.println("YES");
			else
				System.out.println("NO");
		}

		sc.close();
	}
}
