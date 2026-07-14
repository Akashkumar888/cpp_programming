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
			String S = sc.next();

			char[] sorted = S.toCharArray();
			Arrays.sort(sorted);

			boolean possible = true;

			for(int i = 0; i < N / 2; i++)
			{
				char a1 = S.charAt(i);
				char b1 = S.charAt(N - 1 - i);

				char a2 = sorted[i];
				char b2 = sorted[N - 1 - i];

				// Same unordered pair
				if(!((a1 == a2 && b1 == b2) || (a1 == b2 && b1 == a2)))
				{
					possible = false;
					break;
				}
			}

			// Middle character cannot move
			if(possible && N % 2 == 1)
			{
				if(S.charAt(N / 2) != sorted[N / 2])
					possible = false;
			}

			System.out.println(possible ? "YES" : "NO");
		}

		sc.close();
	}
}
