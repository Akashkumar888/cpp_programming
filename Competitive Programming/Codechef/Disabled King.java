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

			// If N is odd, answer = N - 1
			// If N is even, answer = N
			if(N % 2 == 1)
				System.out.println(N - 1);
			else
				System.out.println(N);
		}

		sc.close();
	}
}
