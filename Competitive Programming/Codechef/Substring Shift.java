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
			int N = sc.nextInt();
			char[] s = sc.next().toCharArray();

			int i = 0;

			// Find first 'z'
			while(i < N && s[i] != 'z')
				i++;

			// Convert first contiguous block of 'z' to 'a'
			while(i < N && s[i] == 'z')
			{
				s[i] = 'a';
				i++;
			}

			System.out.println(new String(s));
		}

		sc.close();
	}
}
