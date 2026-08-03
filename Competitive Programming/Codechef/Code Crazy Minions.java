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
			String s = sc.next();

			int instructions = 2; // 1 Load + 1 Print for first character

			for(int i = 1; i < s.length(); i++)
			{
				int prev = s.charAt(i - 1) - 'a';
				int curr = s.charAt(i) - 'a';

				int inc = (curr - prev + 26) % 26;

				instructions += inc + 1; // increments + print
			}

			if(instructions <= 11 * s.length())
				System.out.println("YES");
			else
				System.out.println("NO");
		}

		sc.close();
	}
}
