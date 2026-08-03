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
			long N = sc.nextLong();

			if((N & 1) == 0)   // Even
			{
				if(N % 4 == 0)
					System.out.println(N + 3);
				else
					System.out.println(3);
			}
			else               // Odd
			{
				if(N % 4 == 1)
					System.out.println(N);
				else
					System.out.println(3);
			}
		}

		sc.close();
	}
}
