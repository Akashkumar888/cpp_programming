import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main(String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		int[] minFreq = new int[26];
		Arrays.fill(minFreq, Integer.MAX_VALUE);

		for(int i = 0; i < N; i++)
		{
			String s = sc.next();

			int[] freq = new int[26];

			for(int j = 0; j < s.length(); j++)
			{
				freq[s.charAt(j) - 'a']++;
			}

			for(int j = 0; j < 26; j++)
			{
				minFreq[j] = Math.min(minFreq[j], freq[j]);
			}
		}

		StringBuilder ans = new StringBuilder();

		for(int i = 0; i < 26; i++)
		{
			while(minFreq[i] > 0)
			{
				ans.append((char)('a' + i));
				minFreq[i]--;
			}
		}

		if(ans.length() == 0)
			System.out.println("no such string");
		else
			System.out.println(ans.toString());

		sc.close();
	}
}
