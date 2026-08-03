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

			long backlog = 0;   // Unpaid maintenance fees
			long fine = 0;      // Total fine

			for(int i = 0; i < N; i++)
			{
				int x = sc.nextInt();

				if(x == 0)
				{
					// Current month's fee not paid
					backlog++;
					fine += 100;
				}
				else
				{
					if(backlog > 0)
					{
						// Payment clears the earliest unpaid month,
						// current month becomes unpaid
						fine += 100;
					}
					// backlog remains unchanged
				}
			}

			long ans = backlog * 1000 + fine;

			System.out.println(ans);
		}

		sc.close();
	}
}
