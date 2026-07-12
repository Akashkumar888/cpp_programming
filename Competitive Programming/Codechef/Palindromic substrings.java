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
			String A = sc.next();
			String B = sc.next();

			boolean[] present = new boolean[26];

			// Mark characters present in A
			for(int i = 0; i < A.length(); i++)
			{
				present[A.charAt(i) - 'a'] = true;
			}

			boolean found = false;

			// Check if any character of B is present in A
			for(int i = 0; i < B.length(); i++)
			{
				if(present[B.charAt(i) - 'a'])
				{
					found = true;
					break;
				}
			}

			if(found)
				System.out.println("Yes");
			else
				System.out.println("No");
		}

		sc.close();
	}
}
