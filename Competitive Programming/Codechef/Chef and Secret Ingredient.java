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
			int X = sc.nextInt();

			boolean found = false;

			for(int i = 0; i < N; i++)
			{
				int a = sc.nextInt();

				if(a >= X)
				{
					found = true;
				}
			}

			if(found)
				System.out.println("YES");
			else
				System.out.println("NO");
		}

		sc.close();
	}
}
