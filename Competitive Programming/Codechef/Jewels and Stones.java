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
			String J = sc.next();
			String S = sc.next();

			HashSet<Character> jewels = new HashSet<>();

			for(int i = 0; i < J.length(); i++)
			{
				jewels.add(J.charAt(i));
			}

			int count = 0;

			for(int i = 0; i < S.length(); i++)
			{
				if(jewels.contains(S.charAt(i)))
					count++;
			}

			System.out.println(count);
		}

		sc.close();
	}
}
