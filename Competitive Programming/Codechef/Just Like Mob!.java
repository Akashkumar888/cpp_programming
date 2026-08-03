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
			long M = sc.nextLong();
			long K = sc.nextLong();
			long X = sc.nextLong();

			long cycleDays = K * N + M;

			long rem = (X - 1) % cycleDays;

			if(rem < (K - 1) * N)
				System.out.println("NO");
			else
				System.out.println("YES");
		}

		sc.close();
	}
}
